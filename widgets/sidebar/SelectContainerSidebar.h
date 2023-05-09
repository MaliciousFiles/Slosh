//
// Created by Oakley Randle on 5/3/23.
//

#ifndef SLOSH_SELECTCONTAINERSIDEBAR_H
#define SLOSH_SELECTCONTAINERSIDEBAR_H

#include <QComboBox>
#include "SidebarWidget.h"
#include "../util/NumberInput.h"
#include "../canvas/Container.h"
#include "../canvas/Canvas.h"
#include <QCheckBox>

class SelectContainerSidebar : public SidebarWidget {
    Q_OBJECT

public:
    explicit SelectContainerSidebar(Canvas* canvas, QWidget *parent = nullptr);

private:
    void setSelected(Container* container);
    void setLayoutVisible(bool visible);

    Container* selected;
    QObject* lastClicked;
    NumberInput *temperature;
    NumberInput *volume;
    QCheckBox *lid;
};


#endif //SLOSH_NEWFLUIDSIDEBAR_H
