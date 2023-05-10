//
// Created by Oakley Randle on 5/3/23.
//

#include <QFormLayout>
#include <QLabel>
#include <QFrame>
#include "../../api/MaterialData.h"
#include "EditFluidSidebar.h"
#include "../../util/GlobalClickHandler.h"


EditFluidSidebar::EditFluidSidebar(Canvas* canvas, QWidget *parent) : SidebarWidget(parent), canvas(canvas) {
    volume = new NumberInput(this);
    volume->slider->setRange(10, 1000);
    volume->slider->setTickInterval(99);
    volume->slider->setTickPosition(QSlider::TicksBelow);

    auto layout = new QFormLayout(this);
    layout->setContentsMargins(10, 30, 10, 0);
    layout->setVerticalSpacing(10);
    auto* label = new QLabel("Select a Fluid");
    label->setAlignment(Qt::AlignHCenter);
    layout->addWidget(label);
    layout->addRow(tr("Vol (mL)"), volume);
    setLayout(layout);

    setSelected(nullptr, nullptr);

    for (Container* c : canvas->getContainers()) {
        for (auto& substance : c->getSubstances()) {
            substance.second->setCursor(Qt::PointingHandCursor);
        }
    }

    connect(volume->slider, &QSlider::valueChanged, this, [this] (int value) {
        if (selectedSubstance) {
            selectedSubstance->setVolume(value);
            selected->styleChildren();
        }
    });

    connect(GlobalClickHandler::instance, &GlobalClickHandler::objectClicked, this, [this, canvas](QObject* obj, Qt::MouseButton button, bool& consume) {
        if (button == Qt::LeftButton) {
            bool found = false;

            for (auto container: canvas->getContainers()) {
                for (auto& substance : container->getSubstances()) {
                    if (substance.second == lastClicked) {
                        found = true;
                        setSelected(container, substance.first);
                    }
                }
            }

            if (!found && obj == canvas) {
                setSelected(nullptr, nullptr);
            }

            lastClicked = obj;
        }
    });
    
}

void EditFluidSidebar::setSelected(Container* container, Substance* substance) {
    selected = container;
    selectedSubstance = substance;

    setLayoutVisible(container != nullptr);

    if (container) {
        volume->slider->setValue(substance->getVolume());
    }
}

void EditFluidSidebar::setLayoutVisible(bool visible) {
    auto* form = (QFormLayout*) layout();

    form->setRowVisible(0, !visible);
    for (int i = 1; i < form->rowCount(); i++) form->setRowVisible(i, visible);
}

EditFluidSidebar::~EditFluidSidebar() {
    for (Container* c : canvas->getContainers()) {
        for (auto& substance : c->getSubstances()) {
            substance.second->setCursor(Qt::ArrowCursor);
        }
    }

//    SidebarWidget::~SidebarWidget();
}
