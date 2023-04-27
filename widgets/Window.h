//
// Created by Malcolm Roalson on 4/24/23.
//

#ifndef SLOSH_WINDOW_H
#define SLOSH_WINDOW_H


#include <QWidget>
#include "toolbar/Toolbar.h"
#include "sidebar/Sidebar.h"
#include "canvas/Canvas.h"

class Window : public QWidget {
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);

private:
    Toolbar *toolbar;
    Sidebar *sidebar;
    Canvas *canvas;

    void mouseReleaseEvent(QMouseEvent* event) override;
};


#endif //SLOSH_WINDOW_H
