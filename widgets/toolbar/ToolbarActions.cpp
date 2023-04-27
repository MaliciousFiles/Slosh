//
// Created by Malcolm Roalson on 4/25/23.
//

#include "ToolbarActions.h"
#include "../sidebar/NewFluidSidebar.h"

std::vector<ToolbarActions*> ToolbarActions::ALL = std::vector<ToolbarActions*>();
const ToolbarActions* ToolbarActions::ADD_FLUID = new ToolbarActions("Add Fluid", [] (QWidget* p){return new NewFluidSidebar(p);});
const ToolbarActions* ToolbarActions::REMOVE_FLUID = new ToolbarActions("Remove Fluid");

ToolbarButton *ToolbarActions::widget(QWidget *parent, QSize size) {
    return new ToolbarButton(parent, icon, size, this);
}
