//
// Created by Malcolm Roalson on 4/24/23.
//

#include <QGridLayout>
#include <QMouseEvent>
#include <QApplication>
#include "Window.h"

Window::Window(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Slosh");

    toolbar = new Toolbar();
    canvas = new Canvas();
    sidebar = new Sidebar();

    connect(toolbar, &Toolbar::actionChanged, this,
            [&] (const ToolbarActions* action) {
                   sidebar->setSidebarWidget(action ? action->sidebarWidget(sidebar) : nullptr);
    });

    auto layout = new QGridLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(toolbar, 0, 0);
    layout->addWidget(canvas, 0, 1);
    layout->addWidget(sidebar, 0, 2);
    setLayout(layout);
}

void Window::mouseReleaseEvent(QMouseEvent* event) {
    QWidget* focused = QApplication::focusWidget();

    if (event->button() == Qt::LeftButton && focused && !focused->rect().contains(event->pos())) {
        focused->clearFocus();
    }
}