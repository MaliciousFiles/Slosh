//
// Created by Malcolm Roalson on 5/4/23.
//

#ifndef SLOSH_CHEMICALEQUATION_H
#define SLOSH_CHEMICALEQUATION_H

#include <map>
#include <utility>
#include "Substance.h"

typedef std::map<MaterialData*, int> Side;

class ChemicalEquation {

public:
    enum ReactionType {
        SYNTHESIS,
        SINGLE_REPLACEMENT,
        DOUBLE_REPLACEMENT
    };

    Side reactants;
    Side products;
    ReactionType type;

    ChemicalEquation(Side reactants, Side products, ReactionType type);

    std::string toString();
};


#endif //SLOSH_CHEMICALEQUATION_H
