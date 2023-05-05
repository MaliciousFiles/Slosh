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
    const Side reactants;
    const Side products;

    ChemicalEquation(Side reactants, Side products);
};


#endif //SLOSH_CHEMICALEQUATION_H
