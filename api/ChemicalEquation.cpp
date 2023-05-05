//
// Created by Malcolm Roalson on 5/4/23.
//

#include "ChemicalEquation.h"

ChemicalEquation::ChemicalEquation(Side reactants, Side products) : reactants(std::move(reactants)), products(std::move(products)) {

}