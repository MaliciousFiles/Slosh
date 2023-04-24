//
// Created by Malcolm Roalson on 4/24/23.
//

#ifndef SLOSH_TOOLBAR_H
#define SLOSH_TOOLBAR_H


#include <QWidget>
#include "ToolbarButton.h"

class Toolbar : public QWidget {
    Q_OBJECT

public:
    explicit Toolbar(QWidget *parent = nullptr);

private:
    ToolbarButton* addFluid;
};


#endif //SLOSH_TOOLBAR_H
