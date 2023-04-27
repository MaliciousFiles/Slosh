//
// Created by Malcolm Roalson on 4/24/23.
//

#include "ToolbarButton.h"
#include <QStyle>

ToolbarButton::ToolbarButton(QWidget *parent, const QString &ico, QSize size, ToolbarActions *action)
        : QPushButton(parent), action(action) {
    QPixmap pixmap(":/icons/"+ico);
    QIcon icon(pixmap);
    setIcon(icon);
    setCheckable(true);
    setIconSize(size*0.75);
    setFixedSize(size);
    setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum));
    setStyleSheet(QString("background-color: %1;").arg(QColor(Qt::lightGray).name()));
}