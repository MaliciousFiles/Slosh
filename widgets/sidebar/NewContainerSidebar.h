//
// Created by Oakley Randle on 5/3/23.
//

#ifndef SLOSH_NEWCONTAINERSIDEBAR_H
#define SLOSH_NEWCONTAINERSIDEBAR_H

#include <QComboBox>
#include "SidebarWidget.h"
#include "../util/NumberInput.h"
#include <QCheckBox>

class NewContainerSidebar : public SidebarWidget {
    Q_OBJECT

public:
    explicit NewContainerSidebar(QWidget *parent = nullptr);

private:
    NumberInput *temperature;
    QCheckBox *lid;
};


#endif //SLOSH_NEWFLUIDSIDEBAR_H
