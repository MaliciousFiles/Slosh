//
// Created by pedro on 5/7/2023.
//

#ifndef SLOSH_CONTAINER_H
#define SLOSH_CONTAINER_H

#include <QWidget>
#include <map>
#include "../../api/Substance.h"

class Container : public QWidget {
    Q_OBJECT;

    const static double WH_RATIO; // w/h
    const static double PIXELS_PER_CM; // px/cm
    const static double WALL_WIDTH; // px

    std::map<Substance*, QWidget*> substances;
    double volume; // in mL (aka cm^3)
    double width; // in pixels
    double height; // in pixels
    double temperature; // in K
    bool lidded;

    QPointF* dragStartPos;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;

    void styleChildren();

public:

    explicit Container(int volume, QWidget *parent = nullptr);
    void insertSubstance(Substance* substance);
    void paintEvent(QPaintEvent *event) override;
    void setVolume(double volume);

    inline double getVolume() const { return volume; }
    void setLidded(bool hasLid);

    inline bool hasLid() const { return lidded; }
    void setTemperature(double temp);

    inline double getTemperature() const { return temperature; }

    void setCursor(Qt::CursorShape shape);
};


#endif //SLOSH_CONTAINER_H
