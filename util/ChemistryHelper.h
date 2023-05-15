//
// Created by Malcolm Roalson on 4/28/23.
//

#ifndef SLOSH_CHEMISTRYHELPER_H
#define SLOSH_CHEMISTRYHELPER_H
#include "../api/Substance.h"

#include "../api/Substance.h"
#include "../api/ChemicalEquation.h"

class ChemistryHelper {
//return reactants
//return products
public:
    static double getGibbs(double temp, ChemicalEquation *equation);

    static ChemicalEquation* synthesis(std::string one, int c1, std::string three, int c3, Substance* reactant1, Substance* reactant2);
    static ChemicalEquation* singleReaction(std::string one, int c1, std::string three, int c3, std::string four, int c4, Substance* reactant1, Substance* reactant2);
    static ChemicalEquation* doubleReaction(std::string one, int c1, std::string two, int c2, std::string three, int c3, std::string four, int c4, Substance* reactant1, Substance* reactant2);

    static ChemicalEquation* products(Substance *reactant1, Substance* reactant2);
    static void balanceEquation(ChemicalEquation* equation);
};

#endif //SLOSH_CHEMISTRYHELPER_H
