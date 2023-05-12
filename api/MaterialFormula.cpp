//
// Created by Malcolm Roalson on 5/10/23.
//

#include "MaterialFormula.h"

MaterialFormula::MaterialFormula(std::map<std::string, int> elements) : elements(std::move(elements)) {

};

QString MaterialFormula::toString() const {
    QString formula;
    for (const std::pair<const std::string, int>& element : elements) {
        formula.append(element.first.c_str());
        if (element.second > 1) formula.append(std::to_string(element.second).c_str());
    }
    return formula;
}