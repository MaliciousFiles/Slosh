//
// Created by Malcolm Roalson on 4/28/23.
//

#ifndef SLOSH_CHEMISTRYHELPER_H
#define SLOSH_CHEMISTRYHELPER_H

#include "../api/Substance.h"
#include "../api/ChemicalEquation.h"

class ChemistryHelper {

public:
    static double getGibbs(double temp, ChemicalEquation* equation);
    static ChemicalEquation* getChemicalEquation(Substance** reactants, int numReactants);
};


#endif //SLOSH_CHEMISTRYHELPER_H
