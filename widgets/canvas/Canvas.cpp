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

    addContainer(250)->move(this->width()/2, this->height()/2);
}

Container* Canvas::addContainer(int volume){
    auto *container = new Container(volume, this);
    containers.push_back(container);

    return container;
}

std::vector<Container *> Canvas::getContainers() {
    return containers;
}
