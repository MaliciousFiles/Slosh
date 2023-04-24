#include <QApplication>
#include <QPushButton>
#include "widgets/Window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Window w;
    w.showMaximized();

    return QApplication::exec();
}