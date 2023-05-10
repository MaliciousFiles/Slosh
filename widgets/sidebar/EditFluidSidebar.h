//
// Created by Oakley Randle on 5/3/23.
//

#ifndef SLOSH_EDITFLUIDSIDEBAR_H
#define SLOSH_EDITFLUIDSIDEBAR_H

#include <QComboBox>
#include "SidebarWidget.h"
#include "../util/NumberInput.h"
#include "../canvas/Container.h"
#include "../canvas/Canvas.h"
#include <QCheckBox>

class EditFluidSidebar : public SidebarWidget {
    Q_OBJECT

public:
    explicit EditFluidSidebar(Canvas* canvas, QWidget *parent = nullptr);
    ~EditFluidSidebar() override;

private:
    void setSelected(Container* container, Substance* substance);
    void setLayoutVisible(bool visible);

    Canvas* canvas;
    Container* selected;
    Substance* selectedSubstance;

    QObject* lastClicked;
    NumberInput *volume;
};


#endif //SLOSH_EDITFLUIDSIDEBAR_H
