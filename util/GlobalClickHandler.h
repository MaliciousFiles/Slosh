//
// Created by Oakley Randle on 5/3/23.
//

#ifndef SLOSH_GLOBALCLICKHANDLER_H
#define SLOSH_GLOBALCLICKHANDLER_H

#include <QObject>
#include <QEvent>

class GlobalClickHandler : public QObject {
    Q_OBJECT

public:
    static const GlobalClickHandler* instance;
    GlobalClickHandler() {instance = this;}
    bool eventFilter(QObject* obj, QEvent* event) override;

signals:
    void objectClicked(QObject* obj, Qt::MouseButton button, bool& consume);
};


#endif //SLOSH_GLOBALCLICKHANDLER_H
