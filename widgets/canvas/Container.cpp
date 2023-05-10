//
// Created by pedro on 5/7/2023.
//

#include "Container.h"
#include "../../api/ChemicalEquation.h"
#include "../../util/ChemistryHelper.h"
#include <QtGui>

const double Container::WH_RATIO = 0.75;
const double Container::PIXELS_PER_CM = 30;
const double Container::WALL_WIDTH = 10;

Container::Container(int volume, QWidget *parent) : QWidget(parent), lidded(false), temperature(250) {
    setMouseTracking(true);
    setVolume(volume);

    setCursor(Qt::OpenHandCursor);
}

void Container::setVolume(double volume) {
    this->volume = volume;

    width = cbrt(WH_RATIO*volume);
    height = PIXELS_PER_CM * volume/pow(width, 2);
    width *= PIXELS_PER_CM;

    resize(width+WALL_WIDTH*2, height+WALL_WIDTH*2);
}

void Container::insertSubstance(Substance* substance){
    substances.push_back(substance);
    // TODO: add new substance to substance vector

    ChemicalEquation* equation = ChemistryHelper::getChemicalEquation(substances.data(), substances.size());

    if (ChemistryHelper::getGibbs(temperature, equation) < 0) {
        // TODO: enact reaction
        qDebug() << "Reaction occurred";
    }
}

bool Container::removeSubstance(int index){
    return substances.erase(std::next(substances.begin(), index)) != substances.end();
}

Substance* Container::getSubstance(int index){
    return substances.at(index);
}

void Container::setLidded(bool hasLid) {
    this->lidded = hasLid;

    repaint();
}

void Container::setTemperature(double temp) {
    this->temperature = temp;

    repaint();
}

void Container::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    int modifier = underMouse() && cursor() == Qt::PointingHandCursor ? 20 : 0;

    QPen pen(QColor(160+modifier, 160+modifier, 164+modifier), WALL_WIDTH, Qt::SolidLine);
    painter.setPen(pen);

    // walls
    painter.drawLine(WALL_WIDTH/2, WALL_WIDTH*3/2, WALL_WIDTH/2, height+WALL_WIDTH);
    painter.drawLine(width+WALL_WIDTH*3/2, WALL_WIDTH*3/2, width+WALL_WIDTH*3/2, height+WALL_WIDTH);

    if (lidded) painter.drawLine(WALL_WIDTH, WALL_WIDTH/2, width+WALL_WIDTH, WALL_WIDTH/2);

    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);

    painter.drawLine(WALL_WIDTH/2, height+WALL_WIDTH*3/2, width+WALL_WIDTH*3/2, height+WALL_WIDTH*3/2);

    // background
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(210+modifier, 210+modifier, 210+modifier));
    painter.drawRect(WALL_WIDTH, WALL_WIDTH, width, height);

    // thermometer
    painter.setPen(QPen(QColor(60+modifier, 60+modifier, 60+modifier), 2));
    painter.setBrush(QColor(240+modifier, 240+modifier, 240+modifier));
    painter.drawRect(width, WALL_WIDTH*2, 5, height-WALL_WIDTH*2);

    double pixelsPerDegree = (height-WALL_WIDTH*2-2)/500;
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255+modifier, 1+modifier, 0+modifier));
    painter.drawRect(width+1, height-pixelsPerDegree*temperature-1, 3, pixelsPerDegree*temperature);

    painter.setPen(QPen(QColor(60+modifier, 60+modifier, 60+modifier), 1));
    for (int i = 0; i < 500; i+=10) {
        painter.drawLine(width+3, height-pixelsPerDegree*i-1, width+5, height-pixelsPerDegree*i-1);
    }
}

void Container::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && cursor() == Qt::OpenHandCursor) {
        dragStartPos = new QPointF(pos());

        setCursor(Qt::ClosedHandCursor);
    } else {
        event->setAccepted(false);
    }
}

void Container::mouseMoveEvent(QMouseEvent* event) {
    if (!lidded && event->position().y() < WALL_WIDTH) {
//        setCursor(Qt::ArrowCursor); // TODO: causes problems that I don't really care to fix rn
        return;
    }
    if (!dragStartPos) return;

    if (event->buttons() & Qt::LeftButton) {
        QEventPoint point = event->point(0);

        QPoint newPos = (*dragStartPos + point.globalPosition() - point.globalPressPosition()).toPoint();

        newPos.setX(std::clamp(newPos.x(), 0, parentWidget()->width() - rect().width()));
        newPos.setY(std::clamp(newPos.y(), 0, parentWidget()->height() - rect().height()));

        move(newPos);
    }
}

void Container::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && cursor() == Qt::ClosedHandCursor) {
        delete dragStartPos;
        dragStartPos = nullptr;

        setCursor(Qt::OpenHandCursor);
    }
}
