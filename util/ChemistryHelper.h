//
// Created by Malcolm Roalson on 4/28/23.
//

#ifndef SLOSH_CHEMISTRYHELPER_H
#define SLOSH_CHEMISTRYHELPER_H
#include "../api/Substance.h"

#include "../api/Substance.h"
#include "../api/ChemicalEquation.h"

using namespace std;

class ChemistryHelper {
//return reactants
//return products
public:
    static double getGibbs(double temp, ChemicalEquation *equation);

    static std::string singleReaction(std::string one, std::string three, std::string four);
    static std::string doubleReaction(std::string one, std::string two, std::string three, std::string four);

    static ChemicalEquation *products(Substance *reactant1, Substance* reactant2);
    static void balanceEquation(ChemicalEquation* equation);
}

#endif //SLOSH_CHEMISTRYHELPER_H
