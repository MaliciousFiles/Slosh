//
// Created by Malcolm Roalson on 4/27/23.
//

#ifndef SLOSH_TEXTINPUT_H
#define SLOSH_TEXTINPUT_H

#include <QLineEdit>
#include <QFocusEvent>
#include <QKeyEvent>

class TextInput : public QLineEdit {

public:
    explicit TextInput(QWidget *parent = nullptr);
    void focusInEvent(QFocusEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QString prevValue;
};


#endif //SLOSH_TEXTINPUT_H
