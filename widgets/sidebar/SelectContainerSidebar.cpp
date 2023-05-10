//
// Created by Oakley Randle on 5/3/23.
//

#include <QFormLayout>
#include <QLabel>
#include "../../api/MaterialData.h"
#include "SelectContainerSidebar.h"
#include "../../util/GlobalClickHandler.h"


SelectContainerSidebar::SelectContainerSidebar(Canvas* canvas, QWidget *parent) : SidebarWidget(parent), canvas(canvas) {
    temperature = new NumberInput(this);
    temperature->slider->setRange(0, 3000);
    temperature->slider->setTickInterval(300);
    temperature->slider->setTickPosition(QSlider::TicksBelow);

    volume = new NumberInput(this);
    volume->slider->setRange(50, 1500);
    volume->slider->setTickInterval(145);
    volume->slider->setTickPosition(QSlider::TicksBelow);

    lid = new QCheckBox(this);

    auto layout = new QFormLayout(this);
    layout->setContentsMargins(0, 30, 10, 0);
    layout->setVerticalSpacing(10);
    layout->addWidget(new QLabel("Select a Container"));
    layout->addRow(tr("Vol (mL)"), volume);
    layout->addRow(tr("Temp (k)"), temperature);
    layout->addRow(tr("Lid"), lid);
    setLayout(layout);

    setSelected(nullptr);

    connect(volume->slider, &QSlider::valueChanged, this, [this] (int value) {
        if (selected) selected->setVolume(value);
    });
    connect(temperature->slider, &QSlider::valueChanged, this, [this] (int value) {
        if (selected) selected->setTemperature(value);
    });
    connect(lid, &QCheckBox::stateChanged, this, [this] (int value) {
        if (selected) selected->setLidded(value);
    });

    connect(GlobalClickHandler::instance, &GlobalClickHandler::objectClicked, this, [this, canvas](QObject* obj, Qt::MouseButton button, bool& consume) {
        if (button == Qt::LeftButton) {
            bool found = false;

            for (auto container: canvas->getContainers()) {
                if (container == lastClicked) {
                    found = true;
                    setSelected(container);
                }
            }

            if (!found && obj == canvas) {
                setSelected(nullptr);
            }

            lastClicked = obj;
        }
    });
    
}

void SelectContainerSidebar::setSelected(Container* container) {
    selected = container;

    setLayoutVisible(container != nullptr);

    for (auto* c : canvas->getContainers()) c->setCursor(selected ? Qt::OpenHandCursor : Qt::PointingHandCursor);

    if (container) {
        volume->slider->setValue(container->getVolume());
        temperature->slider->setValue(container->getTemperature());
        lid->setChecked(container->hasLid());
    }
}

void SelectContainerSidebar::setLayoutVisible(bool visible) {
    auto* form = (QFormLayout*) layout();

    form->setRowVisible(0, !visible);
    for (int i = 1; i < form->rowCount(); i++) form->setRowVisible(i, visible);
}

SelectContainerSidebar::~SelectContainerSidebar() {
    for (auto* container : canvas->getContainers()) container->setCursor(Qt::OpenHandCursor);

//    SidebarWidget::~SidebarWidget();
}
