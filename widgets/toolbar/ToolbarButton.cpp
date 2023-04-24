//
// Created by Malcolm Roalson on 4/24/23.
//

#include "ToolbarButton.h"

ToolbarButton::ToolbarButton(const QString& ico, QSize size, QWidget *parent) : QPushButton(parent) {
    QPixmap pixmap(":/icons/"+ico);
    QIcon icon(pixmap);
    setIcon(icon);
    setIconSize(size*0.75);
    setFixedSize(size);
    setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum));

    setStyleSheet(QString("background-color: %1;").arg(QColor(Qt::lightGray).name()));
}