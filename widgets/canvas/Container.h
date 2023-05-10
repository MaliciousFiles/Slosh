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

    const static double WH_RATIO; // w/h
    const static double PIXELS_PER_CM; // px/cm
    const static double WALL_WIDTH; // px

    std::vector<Substance*> substances;
    double volume; // in mL (aka cm^3)
    double width; // in pixels
    double height; // in pixels
    double temperature; // in K
    bool lidded;

    QPointF* dragStartPos;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

public:
    explicit Container(int volume, QWidget *parent = nullptr);
    void insertSubstance(Substance* substance);
    bool removeSubstance(int index);
    Substance* getSubstance(int index);
    void paintEvent(QPaintEvent *event) override;

    void setVolume(double volume);
    inline double getVolume() const { return volume; }

    void setLidded(bool hasLid);
    inline bool hasLid() const { return lidded; }

    void setTemperature(double temp);
    inline double getTemperature() const { return temperature; }
};


#endif //SLOSH_CONTAINER_H
