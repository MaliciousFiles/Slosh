//
// Created by pedro on 5/7/2023.
//

#include "Container.h"
#include <QtGui>

const double Container::WH_RATIO = 0.75;

Container::Container(QWidget *parent, int volume) : QWidget(parent){
    width = cbrt(WH_RATIO*volume);
    height = volume/(pow(width, 2));
    this -> volume = volume;
}

void Container::insertSubstance(Substance* substance, int index){

}

bool Container::removeSubstance(int index){
    return false;
}

Substance* Container::getSubstance(int index){
    return nullptr;
}

void Container::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    QPen pen(Qt::red, 2, Qt::SolidLine);
    painter.setPen(pen);

    painter.drawRect(0, 0, width, height);

}