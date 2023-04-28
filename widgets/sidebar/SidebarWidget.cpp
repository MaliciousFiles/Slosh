//
// Created by Malcolm Roalson on 4/26/23.
//

#include "SidebarWidget.h"

SidebarWidget::SidebarWidget(QWidget *parent) : QWidget(parent) {
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::white);
    setPalette(pal);

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}
