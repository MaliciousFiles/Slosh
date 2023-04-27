//
// Created by Malcolm Roalson on 4/24/23.
//

#ifndef SLOSH_TOOLBARBUTTON_H
#define SLOSH_TOOLBARBUTTON_H


#include <QPushButton>
#include <QWidget>
#include "ToolbarActions.h"

class ToolbarActions;
class ToolbarButton : public QPushButton {
    Q_OBJECT

public:
    const ToolbarActions* action;

    ToolbarButton(QWidget *parent, const QString &ico, QSize size, ToolbarActions *action);
};


#endif //SLOSH_TOOLBARBUTTON_H
