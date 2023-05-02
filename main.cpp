#include <QApplication>
#include "widgets/Window.h"
#include "api/MaterialData.h"
#include "util/TooltipRichTextFilter.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    a.installEventFilter(new TooltipRichTextFilter());

    MaterialData::initFluids();

    Window w;
    w.showMaximized();

    return QApplication::exec();
}