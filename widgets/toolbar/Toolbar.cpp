//
// Created by Malcolm Roalson on 4/24/23.
//

#include <QGridLayout>
#include <QStyle>
#include "Toolbar.h"

Toolbar::Toolbar(QWidget *parent) : QWidget(parent), active(nullptr) {
    auto layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignTop);
    layout->setVerticalSpacing(20);

    for (ToolbarActions* action : ToolbarActions::ALL) {
        ToolbarButton* button = action->widget(this, QSize(40, 40));

        connect(button, &QPushButton::clicked, this, &Toolbar::onButtonClick);

        layout->addWidget(button);

        buttons[action] = button;
    }

    setLayout(layout);

    setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum));

    QPalette pal;
    pal.setColor(QPalette::Window, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(pal);
}

void Toolbar::onButtonClick() {
    auto b = (ToolbarButton*) sender();

    if (active) active->setChecked(false);
    active = b->isChecked() ? b : nullptr;

    emit actionChanged(active ? active->action : nullptr);
}