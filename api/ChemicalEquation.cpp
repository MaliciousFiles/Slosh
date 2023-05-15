//
// Created by Malcolm Roalson on 5/4/23.
//

#include "ChemicalEquation.h"

ChemicalEquation::ChemicalEquation(Side reactants, Side products, ReactionType type) : reactants(std::move(reactants)), products(std::move(products)), type(type) {

}

std::string ChemicalEquation::toString() {
    std::string out = "";
    for (auto const& x : reactants) {
        out += std::to_string(x.second) + " " + x.first->form.toStdString() + " + ";
    }
    out = out.substr(0, out.length()-3);

    out += " → ";

    for (auto const& x : products) {
        out += std::to_string(x.second) + " " + x.first->form.toStdString() + " + ";
    }

    return out.substr(0, out.length()-3);
}
