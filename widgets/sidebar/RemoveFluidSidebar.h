//
// Created by Malcolm on 5/10/2023.
//

#ifndef SLOSH_REMOVEFLUIDSIDEBAR_H
#define SLOSH_REMOVEFLUIDSIDEBAR_H


#include "SidebarWidget.h"
#include "../canvas/Canvas.h"

class RemoveFluidSidebar : public SidebarWidget {

    Canvas* canvas;

public:
    RemoveFluidSidebar(Canvas* canvas, QWidget* parent = nullptr);
    ~RemoveFluidSidebar() override;
};


#endif //SLOSH_REMOVEFLUIDSIDEBAR_H
