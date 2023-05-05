#include <QApplication>
#include "widgets/Window.h"
#include "api/MaterialData.h"
#include "util/TooltipRichTextFilter.h"
#include "util/GlobalClickHandler.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    a.installEventFilter(new TooltipRichTextFilter());
    a.installEventFilter(new GlobalClickHandler());

    MaterialData::initFluids();

    Window w;
    w.showMaximized();

    return QApplication::exec();
}