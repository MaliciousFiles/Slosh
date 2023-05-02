//
// Created by Malcolm Roalson on 4/25/23.
//

#include <QShortcut>
#include "ToolbarActions.h"
#include "../sidebar/NewFluidSidebar.h"

std::vector<ToolbarActions*> ToolbarActions::ALL = std::vector<ToolbarActions*>();
const ToolbarActions* ToolbarActions::ADD_FLUID = new ToolbarActions("Add Fluid", Qt::Key_A, [] (QWidget* p){return new NewFluidSidebar(p);});
const ToolbarActions* ToolbarActions::REMOVE_FLUID = new ToolbarActions("Remove Fluid", Qt::Key_R);
const ToolbarActions* ToolbarActions::EDIT_FLUID = new ToolbarActions("Edit Fluid", Qt::Key_E);

ToolbarActions::ToolbarActions(QString name, Qt::Key key, std::function<SidebarWidget*(QWidget*)> widgetSupplier) : name(std::move(name)), key(key), sidebarWidget(std::move(widgetSupplier)) {
    ALL.push_back(this);
};

ToolbarButton *ToolbarActions::widget(QWidget *parent, QSize size) {
    auto b = new ToolbarButton(parent, name, key, name, size, this);

    new QShortcut(QKeySequence(key), b, b, &ToolbarButton::click);

    return b;
}
