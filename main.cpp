#include <QApplication>
#include "widgets/Window.h"
#include "api/MaterialData.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MaterialData::initFluids();

    Window w;
    w.showMaximized();

    return QApplication::exec();
}