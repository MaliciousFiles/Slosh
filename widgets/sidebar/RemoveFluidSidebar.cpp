//
// Created by Malcolm on 5/10/2023.
//

#include <QLabel>
#include <QFormLayout>
#include "RemoveFluidSidebar.h"
#include "../../util/GlobalClickHandler.h"

RemoveFluidSidebar::RemoveFluidSidebar(Canvas* canvas, QWidget *parent) : SidebarWidget(parent), canvas(canvas) {
    auto* layout = new QFormLayout(this);
    layout->setContentsMargins(10, 30, 10, 0);
    auto* label = new QLabel("Click a Substance to Remove");
    label->setAlignment(Qt::AlignHCenter);
    layout->addWidget(label);
    setLayout(layout);

    for (Container* c : canvas->getContainers()) {
        for (auto& substance : c->getSubstances()) {
            substance.second->setCursor(Qt::PointingHandCursor);
        }
    }

    connect(GlobalClickHandler::instance, &GlobalClickHandler::objectClicked, this, [this, canvas](QObject* obj, Qt::MouseButton button, bool& consume){
        if(button == Qt::LeftButton){
            for(auto container : canvas -> getContainers()) {
                for (auto& substance : container->getSubstances()) {
                    if (substance.second == obj) {
                        container->removeSubstance(substance.first->getMaterial());
                        consume = true;
                        return;
                    }
                }
            }
        }
    });
}

RemoveFluidSidebar::~RemoveFluidSidebar() {
    for (Container* c : canvas->getContainers()) {
        for (auto& substance : c->getSubstances()) {
            substance.second->setCursor(Qt::ArrowCursor);
        }
    }

//    SidebarWidget::~SidebarWidget();
}