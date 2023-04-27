//
// Created by Malcolm Roalson on 4/26/23.
//

#include <QVBoxLayout>
#include "Sidebar.h"

Sidebar::Sidebar(QWidget *parent) : QWidget(parent) {
    setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum));

    setMinimumWidth(300);

    QPalette pal;
    pal.setColor(QPalette::Window, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(pal);

    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

void Sidebar::setSidebarWidget(SidebarWidget *widget) {
    if (!layout()->isEmpty()) delete layout()->takeAt(0)->widget();
    if (widget) layout()->addWidget(widget);
}

