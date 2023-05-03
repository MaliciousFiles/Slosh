//
// Created by Oakley Randle on 5/3/23.
//

#ifndef SLOSH_GLOBALCLICKHANDLER_H
#define SLOSH_GLOBALCLICKHANDLER_H

#include <QObject>
#include <QEvent>

class GlobalClickHandler : public QObject {

public:
    bool eventFilter(QObject* obj, QEvent* event) override;
};


#endif //SLOSH_GLOBALCLICKHANDLER_H
