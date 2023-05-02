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
    static const ToolbarActions* EDIT_FLUID;

    const QString name;
    const Qt::Key key;
    const std::function<SidebarWidget*(QWidget*)> sidebarWidget;

    ToolbarButton* widget(QWidget* parent, QSize size);

private:
//    SidebarWidget* sideWidget;
    ToolbarActions(QString name, Qt::Key key, std::function<SidebarWidget*(QWidget*)> widgetSupplier = [] (QWidget* p) {return nullptr;});
};


#endif //SLOSH_TOOLBARACTIONS_H
