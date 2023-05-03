//
// Created by Oakley Randle on 5/3/23.
//

#include <QFormLayout>
#include "../../api/MaterialData.h"
#include "NewContainerSidebar.h"


NewContainerSidebar::NewContainerSidebar(QWidget *parent) : SidebarWidget(parent) {
    temperature = new NumberInput(this);
    temperature->slider->setRange(0, 500);
    temperature->slider->setTickInterval(50);
    temperature->slider->setTickPosition(QSlider::TicksBelow);
    temperature->slider->setValue(300);

    lid = new QCheckBox(this);

    auto layout = new QFormLayout(this);
    layout->setContentsMargins(0, 30, 10, 0);
    layout->setVerticalSpacing(10);
    layout->addRow(tr("Temp (k)"), temperature);
    layout->addRow(tr("Lid"), lid);
    setLayout(layout);
}
