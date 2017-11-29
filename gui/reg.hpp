////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef GUI_REG_HPP
#define GUI_REG_HPP

////////////////////////////////////////////////////////////////////////////////
#include "ui_reg.h"
#include <QWidget>

////////////////////////////////////////////////////////////////////////////////
namespace gui
{

////////////////////////////////////////////////////////////////////////////////
class reg : public QWidget
{
    Q_OBJECT

public:
    ////////////////////
    explicit reg(int nr, QWidget* parent = nullptr);

private:
    ////////////////////
    Ui::reg ui_;
};


////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif
