//
// Created by pedro on 5/7/2023.
//

#include "Container.h"
#include "../../api/ChemicalEquation.h"
#include "../../util/GlobalClickHandler.h"
//#include "../../util/ChemistryHelper.h"
#include <QtGui>
#include <QLayout>
#include <QGraphicsOpacityEffect>

const double Container::WH_RATIO = 0.75;
const double Container::PIXELS_PER_CM = 30;
const double Container::WALL_WIDTH = 10;

Container::Container(int volume, QWidget *parent) : Clickable(parent), lidded(false), temperature(1000) {
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

    styleChildren();
}

void Container::styleChildren() {
    int i = 0;
    for (auto& s : substances) {
        int h = std::min(PIXELS_PER_CM * s.first->getVolume()/pow(width / PIXELS_PER_CM, 2), height);

        s.second->setGeometry(WALL_WIDTH, WALL_WIDTH + height - i - h, width, h);

        i += h;
    }
}

void Container::insertSubstance(Substance* substance){
    bool found = false;
    for (auto& s : substances) {
        if (s.first->getMaterial() == substance->getMaterial()) {
            s.first->setVolume(s.first->getVolume() + substance->getVolume());
            found = true;
            break;
        }
    }
    if (!found) {
        auto* widget = new QWidget(this);
        widget->show();

        QPalette pal;
        QColor color = substance->getMaterial()->color;
        color.setAlpha(255*0.25);
        pal.setColor(QPalette::Window, color);
        widget->setAutoFillBackground(true);
        widget->setPalette(pal);

        substances[substance] = widget;
    }

    styleChildren();

    /*
    ChemicalEquation* equation = ChemistryHelper::getChemicalEquation(substances.data(), substances.size());

    if (ChemistryHelper::getGibbs(temperature, equation) < 0) {
        // TODO: enact reaction
        qDebug() << "Reaction occurred";
    }*/
}

void Container::setLidded(bool hasLid) {
    this->lidded = hasLid;

    repaint();
}

void Container::setTemperature(double temp) {
    this->temperature = temp;

    repaint();
}

void Container::setCursor(Qt::CursorShape shape) {
    QWidget::setCursor(shape);


}

void Container::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    QPen pen(QColor(160, 160, 164), WALL_WIDTH, Qt::SolidLine);
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
    painter.setBrush(QColor(210, 210, 210));
    painter.drawRect(WALL_WIDTH, WALL_WIDTH, width, height);

    // thermometer
    painter.setPen(QPen(QColor(60, 60, 60), 2));
    painter.setBrush(QColor(240, 240, 240));
    painter.drawRect(width, WALL_WIDTH*2, 5, height-WALL_WIDTH*2);

    double pixelsPerDegree = (height-WALL_WIDTH*2-2)/3000;
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255, 1, 0));
    painter.drawRect(width+1, height-pixelsPerDegree*temperature-1, 3, pixelsPerDegree*temperature);

    painter.setPen(QPen(QColor(60, 60, 60), 1));
    for (int i = 0; i < 3000; i+=60) {
        painter.drawLine(width+3, height-pixelsPerDegree*i-1, width+5, height-pixelsPerDegree*i-1);
    }
}

void Container::removeSubstance(MaterialData* material) {
    for (auto& s : substances) {
        if (s.first->getMaterial() == material) {
            substances.erase(substances.find(s.first));
            delete s.second;
            styleChildren();
            return;
        }
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
