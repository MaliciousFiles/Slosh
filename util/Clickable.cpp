//
// Created by Malcolm on 5/10/2023.
//

#include <QGraphicsOpacityEffect>
#include "Clickable.h"

Clickable::Clickable(QWidget *parent) : QWidget(parent), clickable(false) {
    setGraphicsEffect(new QGraphicsOpacityEffect(this));
    ((QGraphicsOpacityEffect*) graphicsEffect())->setOpacity(1);
}

void Clickable::setClickable(bool clickable, Qt::CursorShape defaultCursor) {
    this->clickable = clickable;
    setCursor(clickable ? Qt::PointingHandCursor : defaultCursor);

    ((QGraphicsOpacityEffect*) graphicsEffect())->setOpacity(underMouse() && clickable ? 0.75 : 1.0);
}

void Clickable::enterEvent(QEnterEvent *event) {
    ((QGraphicsOpacityEffect*) graphicsEffect())->setOpacity(clickable ? 0.75 : 1.0);
}

void Clickable::leaveEvent(QEvent *event) {
    ((QGraphicsOpacityEffect*) graphicsEffect())->setOpacity(1.0);
}
