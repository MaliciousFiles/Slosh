//
// Created by Malcolm Roalson on 5/2/23.
//

#include "TooltipRichTextFilter.h"

#include <QWidget>
#include <QString>
#include <QtGui>

bool TooltipRichTextFilter::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::ToolTipChange) {
        if (!obj->isWidgetType()) return false;
        auto widget = (QWidget*) obj;

        QString tooltip = widget->toolTip();

        if (!Qt::mightBeRichText(tooltip)) {
            widget->setToolTip("<qt>"+tooltip
                .replace('&', "&amp;")
                .replace('<', "&lt;")
                .replace('>', "&gt;")
                .replace('"', "&quot;")
                .replace('\'', "&apos;")+"</qt>");

            return true;
        }
    }

    return QObject::eventFilter(obj, event);
}