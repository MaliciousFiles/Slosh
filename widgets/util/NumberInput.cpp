//
// Created by Malcolm Roalson on 4/27/23.
//

#include <QHBoxLayout>
#include <QIntValidator>
#include "NumberInput.h"

NumberInput::NumberInput(Qt::Orientation orientation, QWidget *parent) : QWidget(parent) {
    input = new TextInput(this);
    input->setValidator(new QIntValidator(this));
    input->setFocusPolicy(Qt::StrongFocus);

    slider = new QSlider(orientation, this);
    slider->setFocusPolicy(Qt::StrongFocus);

    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(slider, 6);
    layout->addWidget(input, 1);
    setLayout(layout);

    connect(input, &QLineEdit::textChanged, this, &NumberInput::inputValueChanged);
    connect(slider, &QSlider::valueChanged, this, &NumberInput::sliderValueChanged);
}

void NumberInput::inputValueChanged(const QString& value) {
    slider->setValue(value.toInt());
}

void NumberInput::sliderValueChanged(const int &value) {
    input->setText(QString::number(value));
}