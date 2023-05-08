//
// Created by Malcolm Roalson on 4/24/23.
//

#include <QGridLayout>
#include "Canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    QPalette pal;
    pal.setColor(QPalette::Window, Qt::lightGray);
    setAutoFillBackground(true);
    setPalette(pal);

    addContainer(250);
}

void Canvas::addContainer(int volume){
    auto *newContainer = new Container(this, volume);
    newContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    containedContainers.push_back(newContainer);
}