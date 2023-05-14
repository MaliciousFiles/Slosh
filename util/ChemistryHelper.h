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

    static MaterialData* synthesis(std::string one, int c1, std::string three, int c3);
    static MaterialData* singleReaction(std::string one, int c1, std::string three, int c3, std::string four, int c4);
    static MaterialData* doubleReaction(std::string one, int c1, std::string two, int c2, std::string three, int c3, std::string four, int c4);

    static ChemicalEquation *products(Substance *reactant1, Substance* reactant2);
    static void balanceEquation(ChemicalEquation* equation);
}

#endif //SLOSH_CHEMISTRYHELPER_H
