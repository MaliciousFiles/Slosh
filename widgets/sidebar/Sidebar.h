//
// Created by Malcolm Roalson on 4/26/23.
//

#ifndef SLOSH_SIDEBAR_H
#define SLOSH_SIDEBAR_H

#include <QWidget>
#include "SidebarWidget.h"

class Sidebar : public QWidget {
    Q_OBJECT

public:
    explicit Sidebar(QWidget *parent = nullptr);
    void setSidebarWidget(SidebarWidget* widget);
};


#endif //SLOSH_SIDEBAR_H
