//
// Created by Malcolm Roalson on 4/24/23.
//

#include <QGridLayout>
#include "Window.h"

Window::Window(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Slosh");

    toolbar = new Toolbar();
    canvas = new Canvas();

    auto layout = new QGridLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(toolbar, 0, 0);
    layout->addWidget(canvas, 0, 1);
    setLayout(layout);
}