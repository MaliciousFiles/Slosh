//
// Created by Malcolm Roalson on 4/27/23.
//

#ifndef SLOSH_NUMBERINPUT_H
#define SLOSH_NUMBERINPUT_H

#include <QWidget>
#include <QSlider>
#include "TextInput.h"

class NumberInput : public QWidget {
    Q_OBJECT

public:
    explicit NumberInput(QWidget *parent = nullptr) : NumberInput(Qt::Horizontal, parent) {}
    explicit NumberInput(Qt::Orientation orientation, QWidget *parent = nullptr);

    QSlider* slider;
    TextInput* input;

public slots:
    void inputValueChanged(const QString& value) const;
    void sliderValueChanged(const int& value) const;
};


#endif //SLOSH_NUMBERINPUT_H
