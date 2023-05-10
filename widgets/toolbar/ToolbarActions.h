//
// Created by Malcolm Roalson on 4/25/23.
//

#ifndef SLOSH_TOOLBARACTIONS_H
#define SLOSH_TOOLBARACTIONS_H


#include <QString>
#include <utility>
#include "ToolbarButton.h"
#include "../sidebar/SidebarWidget.h"
#include "../Window.h"

class ToolbarButton;
class Window;

class ToolbarActions {
public:
    static std::vector<ToolbarActions*> ALL;
    static const ToolbarActions* ADD_FLUID;
    static const ToolbarActions* REMOVE_FLUID;
    static const ToolbarActions* EDIT_FLUID;
    static const ToolbarActions* EDIT_CONTAINER;

    const QString name;
    const Qt::Key key;
    const std::function<SidebarWidget*(Window*)> sidebarWidget;

    ToolbarButton* widget(QWidget* parent, QSize size);

private:
    ToolbarActions(QString name, Qt::Key key, std::function<SidebarWidget*(Window*)> widgetSupplier = [] (Window* w) {return nullptr;});
};


#endif //SLOSH_TOOLBARACTIONS_H
