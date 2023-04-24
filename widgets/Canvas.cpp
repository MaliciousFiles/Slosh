//
// Created by Malcolm Roalson on 4/24/23.
//

#include <QGridLayout>
#include "Canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    QPalette pal;
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
}