//
// Created by pedro on 5/7/2023.
//

#ifndef SLOSH_CONTAINER_H
#define SLOSH_CONTAINER_H

#include <QWidget>
#include <map>
#include "../../api/Substance.h"
#include "../../util/Clickable.h"

class Container : public Clickable {
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

public:

    void styleChildren();

    explicit Container(int volume, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

    inline double getVolume() const { return volume; }
    void setVolume(double volume);

    inline bool hasLid() const { return lidded; }
    void setLidded(bool hasLid);

    inline double getTemperature() const { return temperature; }
    void setTemperature(double temp);

    inline std::map<Substance*, QWidget*> getSubstances() const { return substances; }
    void insertSubstance(Substance* substance);
    void removeSubstance(MaterialData* material);

    void setCursor(Qt::CursorShape shape);
};


#endif //SLOSH_CONTAINER_H
