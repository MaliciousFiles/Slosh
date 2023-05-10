//
// Created by Malcolm Roalson on 4/26/23.
//

#include <QFormLayout>
#include "../../api/MaterialData.h"
#include "NewFluidSidebar.h"
#include "../canvas/Canvas.h"
#include "../../util/GlobalClickHandler.h"
#include "../canvas/Container.h"
#include "../../api/MaterialData.h"

NewFluidSidebar::NewFluidSidebar(Canvas* canvas, QWidget *parent) : SidebarWidget(parent), canvas(canvas) {
    pickFluid = new QComboBox(this);
    QPalette pickPal;
    pickPal.setColor(QPalette::Window, Qt::transparent);
    pickFluid->setPalette(pickPal);
    for (const std::pair<const std::string, MaterialData *>& d : MaterialData::FLUIDS) pickFluid->insertItem(0, d.first.c_str());
    pickFluid->setCurrentIndex(0);
    pickFluid->setFocusPolicy(Qt::TabFocus);

    volume = new NumberInput(this);
    volume->slider->setRange(1, 100);
    volume->slider->setTickInterval(10);
    volume->slider->setTickPosition(QSlider::TicksBelow);
    volume->slider->setValue(500);

    auto layout = new QFormLayout(this);
    layout->setContentsMargins(10, 30, 10, 0);
    layout->setVerticalSpacing(10);
    layout->addRow(tr("Fluid"), pickFluid);
    layout->addRow(tr("Vol (mL)"), volume);
    setLayout(layout);

    for (auto* c : canvas->getContainers()) c->setClickable(true);

    connect(GlobalClickHandler::instance, &GlobalClickHandler::objectClicked, this, [this, canvas](QObject* obj, Qt::MouseButton button, bool& consume){
        if(button == Qt::LeftButton){
            for(auto container : canvas -> getContainers()){
                if(container == obj){
                    // TODO: use correct state
                    container -> insertSubstance(new Substance(MaterialData::FLUIDS[pickFluid -> currentText().toStdString()], volume->slider->value(), Substance::State::AQUEOUS));
                    consume = true;
                }
            }
        }
    });
}

NewFluidSidebar::~NewFluidSidebar() {
    for (auto* container : canvas->getContainers()) container->setClickable(false, Qt::OpenHandCursor);

//    SidebarWidget::~SidebarWidget();
}

