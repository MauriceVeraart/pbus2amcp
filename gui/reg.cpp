////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#include "reg.hpp"
#include "ui_reg.h"

////////////////////////////////////////////////////////////////////////////////
namespace gui
{

////////////////////////////////////////////////////////////////////////////////
reg::reg(int nr, QWidget* parent) : QWidget(parent),
    ui(new Ui::reg), nr_(nr)
{
    ui->setupUi(this);
    ui->nr->setText(QString::number(nr));

    if(nr >= 1 && nr <= 9)
    {
        ui->nr->setBuddy(ui->path);
        ui->nr->setText("&" + ui->nr->text());
    }
}

////////////////////////////////////////////////////////////////////////////////
reg::~reg()
{
    delete ui;
}

////////////////////////////////////////////////////////////////////////////////
}
