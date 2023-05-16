//
// Created by Malcolm Roalson on 4/24/23.
//

#ifndef SLOSH_CANVAS_H
#define SLOSH_CANVAS_H


#include <QWidget>
#include <QLabel>
#include "Container.h"


class Canvas : public QWidget {
    Q_OBJECT

    QLabel* mascot;
    std::vector<Container*> containers;

    void resizeEvent(QResizeEvent *event) override;

public:
    explicit Canvas(QWidget *parent = nullptr);
    Container* addContainer(int volume);
    std::vector<Container*> getContainers();
};


#endif //SLOSH_CANVAS_H
