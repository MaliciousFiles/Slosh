//
// Created by Malcolm Roalson on 4/24/23.
//

#ifndef SLOSH_TOOLBAR_H
#define SLOSH_TOOLBAR_H


#include <QWidget>
#include <map>
#include "ToolbarActions.h"
#include "ToolbarButton.h"

class Toolbar : public QWidget {
    Q_OBJECT

public:
    explicit Toolbar(QWidget *parent = nullptr);

signals:
    void actionChanged(const ToolbarActions* action);

public slots:
    void onButtonClick();

private:
    std::map<ToolbarActions*, ToolbarButton*> buttons;
    ToolbarButton* active;
};


#endif //SLOSH_TOOLBAR_H
