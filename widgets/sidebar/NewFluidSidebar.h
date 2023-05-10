//
// Created by Malcolm Roalson on 4/26/23.
//

#ifndef SLOSH_NEWFLUIDSIDEBAR_H
#define SLOSH_NEWFLUIDSIDEBAR_H

#include <QComboBox>
#include "SidebarWidget.h"
#include "../util/NumberInput.h"
#include "../canvas/Canvas.h"

class NewFluidSidebar : public SidebarWidget {
    Q_OBJECT

public:
    explicit NewFluidSidebar(Canvas* canvas, QWidget *parent = nullptr);
    ~NewFluidSidebar() override;

private:
    Canvas* canvas;
    QComboBox *pickFluid;
    NumberInput *volume;
};


#endif //SLOSH_NEWFLUIDSIDEBAR_H
