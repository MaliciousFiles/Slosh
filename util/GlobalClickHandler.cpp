//
// Created by Oakley Randle on 5/3/23.
//

#include "GlobalClickHandler.h"

#include <QWidget>
#include <QString>
#include <QtGui>

const GlobalClickHandler* GlobalClickHandler::instance = nullptr;

bool GlobalClickHandler::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::MouseButtonPress) {
        auto mouseEvent = (QMouseEvent*) event;

        bool consume = false;
        emit(objectClicked(obj, mouseEvent->button(), consume));
        return consume;
    }

    return QObject::eventFilter(obj, event);
}