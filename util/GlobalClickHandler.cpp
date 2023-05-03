//
// Created by Oakley Randle on 5/3/23.
//

#include "GlobalClickHandler.h"

#include <QWidget>
#include <QString>
#include <QtGui>

bool GlobalClickHandler::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::mousePressEvent) {
        if(event->button() == Qt::LeftButton){
            qDebug()<<"Left Click";
            return true;
        }
    }

    return QObject::eventFilter(obj, event);
}