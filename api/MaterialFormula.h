//
// Created by Malcolm Roalson on 5/10/23.
//

#ifndef SLOSH_MATERIALFORMULA_H
#define SLOSH_MATERIALFORMULA_H

#include <map>
#include <utility>
#include <string>
#include <vector>
#include <QtCore/QString>

class MaterialFormula {

public:
    std::vector<std::pair<std::string, int>> elements;

    explicit MaterialFormula(std::vector<std::pair<std::string, int>> elements);
    QString toString() const;
};


#endif //SLOSH_MATERIALFORMULA_H
