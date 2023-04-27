//
// Created by Malcolm Roalson on 4/26/23.
//

#include <QFormLayout>
#include "../../api/FluidData.h"
#include "NewFluidSidebar.h"

NewFluidSidebar::NewFluidSidebar(QWidget *parent) : SidebarWidget(parent) {
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::white);
    setPalette(pal);

    pickFluid = new QComboBox(this);
    QPalette pickPal;
    pickPal.setColor(QPalette::Window, Qt::transparent);
    pickFluid->setPalette(pickPal);
    for (const std::pair<const std::string, FluidData *>& d : FluidData::FLUIDS) pickFluid->insertItem(0,d.first.c_str());
    pickFluid->setCurrentIndex(0);
    pickFluid->setFocusPolicy(Qt::StrongFocus);

    mass = new NumberInput(this);
    mass->slider->setRange(1, 1000);
    mass->slider->setTickInterval(100);
    mass->slider->setTickPosition(QSlider::TicksBelow);
    mass->slider->setValue(500);

    auto layout = new QFormLayout(this);
    layout->setContentsMargins(0, 30, 10, 0);
    layout->setVerticalSpacing(10);
    layout->addRow(tr("Fluid"), pickFluid);
    layout->addRow(tr("Mass (mL)"), mass);
    setLayout(layout);
}
