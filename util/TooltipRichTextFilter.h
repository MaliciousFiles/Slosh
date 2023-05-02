//
// Created by Malcolm Roalson on 5/2/23.
//

#ifndef SLOSH_TOOLTIPRICHTEXTFILTER_H
#define SLOSH_TOOLTIPRICHTEXTFILTER_H

#include <QObject>
#include <QEvent>

class TooltipRichTextFilter : public QObject {

public:

    bool eventFilter(QObject* obj, QEvent* event) override;
};


#endif //SLOSH_TOOLTIPRICHTEXTFILTER_H
