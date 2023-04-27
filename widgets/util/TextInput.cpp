//
// Created by Malcolm Roalson on 4/27/23.
//

#include "TextInput.h"

TextInput::TextInput(QWidget *parent) : QLineEdit(parent) {
    setFocusPolicy(Qt::StrongFocus);
}

void TextInput::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Escape:
            setText(prevValue);
        case Qt::Key_Return:
        case Qt::Key_Enter:
            clearFocus();
            break;
        default:
            QLineEdit::keyPressEvent(event);
            break;
    }
}

void TextInput::focusInEvent(QFocusEvent *event) {
    prevValue = text();

    selectAll();
    QLineEdit::focusInEvent(event);
}