//
// Created by Malcolm on 5/10/2023.
//

#ifndef SLOSH_CLICKABLE_H
#define SLOSH_CLICKABLE_H

#include <QWidget>

class Clickable : public QWidget {
    Q_OBJECT

    bool clickable;

    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;

public:
    explicit Clickable(QWidget* parent = nullptr);

    void setClickable(bool clickable, Qt::CursorShape defaultCursor = Qt::ArrowCursor);
};


#endif //SLOSH_CLICKABLE_H
