//
// Created by Malcolm Roalson on 4/25/23.
//

#include <QShortcut>
#include "ToolbarActions.h"
#include "../sidebar/NewFluidSidebar.h"
#include "../sidebar/SelectContainerSidebar.h"
#include "../sidebar/RemoveFluidSidebar.h"
#include "../sidebar/EditFluidSidebar.h"

std::vector<ToolbarActions*> ToolbarActions::ALL = std::vector<ToolbarActions*>();
const ToolbarActions* ToolbarActions::ADD_FLUID = new ToolbarActions("Add Fluid", Qt::Key_A, [] (Window* w){return new NewFluidSidebar(w->getCanvas(), w->getSidebar());});
const ToolbarActions* ToolbarActions::REMOVE_FLUID = new ToolbarActions("Remove Fluid", Qt::Key_R, [] (Window* w){return new RemoveFluidSidebar(w->getCanvas(), w->getSidebar());});
const ToolbarActions* ToolbarActions::EDIT_FLUID = new ToolbarActions("Edit Fluid", Qt::Key_E, [] (Window* w){return new EditFluidSidebar(w->getCanvas(), w->getSidebar());});
const ToolbarActions* ToolbarActions::EDIT_CONTAINER = new ToolbarActions("Edit Container", Qt::Key_C, [] (Window* w){return new SelectContainerSidebar(w->getCanvas(), w->getSidebar());});

ToolbarActions::ToolbarActions(QString name, Qt::Key key, std::function<SidebarWidget*(Window*)> widgetSupplier) : name(std::move(name)), key(key), sidebarWidget(std::move(widgetSupplier)) {
    ALL.push_back(this);
};

ToolbarButton *ToolbarActions::widget(QWidget *parent, QSize size) {
    auto b = new ToolbarButton(parent, name, key, name, size, this);

    new QShortcut(QKeySequence(key), b, b, &ToolbarButton::click);

    return b;
}
