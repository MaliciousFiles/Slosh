//
// Created by pedro on 5/7/2023.
//

#ifndef SLOSH_CONTAINER_H
#define SLOSH_CONTAINER_H

#include <QWidget>
#include "../../api/Substance.h"

/*
 * To-do list:
 * 1. make a visual representation of a container that is 3 rectangles arranged to make a U shape as well as graduations
 * 2. Add ability for container to store what liquids it has inside.
 * 3. Represent liquids as colored rectangles stacked on top of each other.
 * 4.
 */

class Container : public QWidget {
    Q_OBJECT;
    std::vector<Substance*> storedSubstances;
    int volume;
    double width;
    double height;
    const static double WH_RATIO;

public:
    Container(QWidget *parent, int volume);
    void insertSubstance(Substance* substance, int index);
    bool removeSubstance(int index);
    Substance* getSubstance(int index);
    void paintEvent(QPaintEvent *event) override;
};


#endif //SLOSH_CONTAINER_H
