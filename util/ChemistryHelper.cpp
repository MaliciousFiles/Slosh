//
// Created by Malcolm Roalson on 4/28/23.
//

#include "ChemistryHelper.h"

double ChemistryHelper::getGibbs(double temp, ChemicalEquation* equation) {
    double enthalpy = 0;
    double entropy = 0;
    for (const auto& pair : equation->products) {
        enthalpy += pair.first->enthalpyFormation;
        entropy += pair.first->entropy;
    }
    for (const auto& pair : equation->reactants) {
        enthalpy -= pair.first->enthalpyFormation;
        entropy -= pair.first->entropy;
    }

    return enthalpy - (temp * entropy);
}

ChemicalEquation *ChemistryHelper::getChemicalEquation(Substance **reactants, int numReactants) {
    // TODO: figure out products and put it into a ChemicalEquation
    return nullptr;
}
