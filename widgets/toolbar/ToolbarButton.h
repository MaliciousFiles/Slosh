//
// Created by Malcolm Roalson on 4/24/23.
//

#ifndef SLOSH_TOOLBARBUTTON_H
#define SLOSH_TOOLBARBUTTON_H


#include <QPushButton>
#include <QWidget>

class ToolbarButton : public QPushButton {
    Q_OBJECT

public:
    explicit ToolbarButton(const QString& ico, QSize size, QWidget *parent = nullptr);
};


#endif //SLOSH_TOOLBARBUTTON_H
