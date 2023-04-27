#include <QApplication>
#include <QPushButton>
#include "widgets/Window.h"
#include "api/FluidData.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    FluidData::initFluids();

    Window w;
    w.showMaximized();

    return QApplication::exec();
}