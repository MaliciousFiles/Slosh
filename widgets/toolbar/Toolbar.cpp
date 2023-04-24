//
// Created by Malcolm Roalson on 4/24/23.
//

#include <QGridLayout>
#include <QStyle>
#include "Toolbar.h"

Toolbar::Toolbar(QWidget *parent) : QWidget(parent) {
    addFluid = new ToolbarButton("Add Fluid", QSize(40, 40));

    auto layout = new QGridLayout();
    layout->setAlignment(Qt::AlignTop);
    layout->addWidget(addFluid, 0, 0);
    setLayout(layout);

    setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum));

    QPalette pal;
    pal.setColor(QPalette::Window, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(pal);
}
