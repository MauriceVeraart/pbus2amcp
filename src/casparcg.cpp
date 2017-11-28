////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#include "casparcg.hpp"

////////////////////////////////////////////////////////////////////////////////
#define VOID(cl, fn, ...) static_cast<void(cl::*)(__VA_ARGS__)>(&cl::fn)

////////////////////////////////////////////////////////////////////////////////
namespace src
{

////////////////////////////////////////////////////////////////////////////////
casparcg::casparcg(const QString& name, quint16 port, QObject* parent) :
    QObject(parent)
{
    connect(&socket_, &QTcpSocket::connected, this, &casparcg::opened);
    connect(&socket_, &QTcpSocket::disconnected, this, &casparcg::closed);

    connect(&socket_, VOID(QTcpSocket, error, QTcpSocket::SocketError),
        [&](){ emit failed(socket_.errorString()); }
    );

    socket_.connectToHost(name, port);
}

////////////////////////////////////////////////////////////////////////////////
void casparcg::scan()
{
    amcp_.reset(new amcp(socket_, "CLS"));

    connect(&*amcp_, &amcp::success, this, &casparcg::proc_scan);
    connect(&*amcp_, &amcp::failure, this, &casparcg::failed);
}

////////////////////////////////////////////////////////////////////////////////
void casparcg::proc_scan(const QByteArrayList& data)
{
    emit scanned(QList<media>());
}

////////////////////////////////////////////////////////////////////////////////
}
