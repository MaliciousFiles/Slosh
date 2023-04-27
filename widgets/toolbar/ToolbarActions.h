//
// Created by Malcolm Roalson on 4/25/23.
//

#ifndef SLOSH_TOOLBARACTIONS_H
#define SLOSH_TOOLBARACTIONS_H


#include <QString>
#include <utility>
#include "ToolbarButton.h"
#include "../sidebar/SidebarWidget.h"

class ToolbarButton;
class ToolbarActions {
public:
    static std::vector<ToolbarActions*> ALL;
    static const ToolbarActions* ADD_FLUID;
    static const ToolbarActions* REMOVE_FLUID;

    const QString icon;
    const std::function<SidebarWidget*(QWidget*)> sidebarWidget;

    ToolbarButton* widget(QWidget* parent, QSize size);

private:
//    SidebarWidget* sideWidget;
    explicit ToolbarActions(QString icon, std::function<SidebarWidget*(QWidget*)> widgetSupplier = [] (QWidget* p) {return nullptr;}) : icon(std::move(icon)), sidebarWidget(std::move(widgetSupplier)) { ALL.push_back(this); };
};


#endif //SLOSH_TOOLBARACTIONS_H
