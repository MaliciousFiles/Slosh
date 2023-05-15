//
// Created by Malcolm Roalson on 4/28/23.
//

#include "ChemistryHelper.h"
#include "../api/ChemicalEquation.h"
#include <fstream>
#include <string>

//chemical reaction for a synthesis reaction
//@paran string one is an element with charge c1 and string three is an element with charge c3
//@return MaterialData* product1 and product2
ChemicalEquation ChemistryHelper::synthesis(std::string one, int c1, std::string three, int c3, Substance* reactant1, Substance* reactant2) {
    ifstream myfile ("Elements.csv");
    string line, ion;
    if (myfile.is_open()) {
        getline(myfile, line);
        while (getline(myfile, line)) {
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ',') {
                    if(one == line.substr(1, i - 2)) {
                        c1 = stoi(line.substr(i+1,1));
                        ion = line.substr(i+3,6);
                    }
                    if(three == line.substr(1, i - 2)) {
                        c3 = stoi(line.substr(i+1,1));
                        ion = line.substr(i+3,6);
                    }
                }
            }
        }
        myfile.close();
    }
    Substance* product = new Substance(MaterialData::SUBSTANCES[MaterialFormula({{one, c3}, {three, c1}}).toString().toStdString()], reactant1->getVolume()+reactant2->getVolume(), Substance::SOLID);
    return ChemicalEquation({{reactant1->getMaterial(),1}, {reactant2->getMaterial(),1}},{{product->getMaterial(),1}});
}

//chemical reaction for a single-replacement reaction
//@param string one is an element with charge c1
    //string three and four are the elements of a single compound with charges c3 and c4 respectively
//@return MaterialData* product1 and product2
ChemicalEquation ChemistryHelper::singleReaction(std::string one, int c1, std::string three, int c3, std::string four, int c4, Substance* reactant1, Substance* reactant2) {
    ifstream myfile ("Elements.csv");
    string line, ion;
    if (myfile.is_open()) {
        getline(myfile, line);
        while (getline(myfile, line)) {
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ',') {
                    if(one == line.substr(1, i - 2)) {
                        c1 = stoi(line.substr(i+1,1));
                        ion = line.substr(i+3,6);
                    }
                }
            }
        }
        myfile.close();
    }
    MaterialData* p1;
    MaterialData* p2;
    if (ion == "cation") {
        p1 = MaterialData::SUBSTANCES[MaterialFormula({{one, c4}, {four, c1}}).toString().toStdString()];
        if (three == "H" || three == "N" || three == "O" || three == "F" || three == "Cl" || three == "I" || three == "Br") {
            p2 = MaterialData::SUBSTANCES[MaterialFormula({{three, 2}}).toString().toStdString()];
        }
        else {p2 = MaterialData::SUBSTANCES[MaterialFormula({{three, 1}}).toString().toStdString()];}
    }
    else {
        p1 = MaterialData::SUBSTANCES[MaterialFormula({{three, c1}, {one, c3}}).toString().toStdString()];
        if (four == "H" || four == "N" || four == "O" || four == "F" || four == "Cl" || four == "I" || four == "Br") {
            p2 = MaterialData::SUBSTANCES[MaterialFormula({{four, 2}}).toString().toStdString()];
        }
        else {p2 = MaterialData::SUBSTANCES[MaterialFormula({{four, 1}}).toString().toStdString()];}
    }
    Substance* product1;
    product1->setMaterial(p1);
    product1->setState(Substance::AQUEOUS);
    Substance* product2;
    product2->setMaterial(p2);
    if (p2->form == "H2" || p2->form == "N2" || p2->form == "O2" || p2->form == "F2"|| p2->form == "Cl2") {
        product2->setState(Substance::GAS);
    }
    else if (p2->form == "I2") {product2->setState(Substance::SOLID);}
    else if (p2->form == "Br2") {product2->setState(Substance::LIQUID);}
    else {product2->setState(Substance::AQUEOUS);}
    return ChemicalEquation({{reactant1->getMaterial(),1}, {reactant2->getMaterial(),1}},{{product1->getMaterial(),1},{product2->getMaterial(),1}});
    //state for product2 is s unless it's a diatomic
}

//chemical reaction for a double-replacement reaction
//@param string one and two are elements of a single compound with charges c1 and c2 respectively
    //string three and four are the elements of a single compound with charges c3 and c4 respectively
//@return MaterialData* product1 and product2
ChemicalEquation ChemistryHelper::doubleReaction(std::string one, int c1, std::string two, int c2, std::string three,int c3, std::string four, int c4, Substance* reactant1, Substance* reactant2) {
    Substance* product1;
    product1->setMaterial(MaterialData::SUBSTANCES[MaterialFormula({{one, c4}, {four, c1}}).toString().toStdString()]);
    product1->setState(Substance::AQUEOUS);
    Substance* product2;
    product2->setMaterial(MaterialData::SUBSTANCES[MaterialFormula({{two, c3}, {three, c4}}).toString().toStdString()]);
    product2->setState(Substance::AQUEOUS);
    return ChemicalEquation({{reactant1->getMaterial(),1}, {reactant2->getMaterial(),1}},{{product1->getMaterial(),1},{product2->getMaterial(),1}});
}

//finds the products and returns chemical equation
//@param two reactants that undergo the chemical reaction
//@return ChemicalEquation of reactants and products
ChemicalEquation ChemistryHelper::products(Substance* reactant1, Substance* reactant2) {
    std::string part1, part2, part3, part4;
    int charge1 =1, charge2 =1, charge3 =1, charge4 = 1;
    int temp = 0;
    for (auto i : reactant1->getMaterial()->formula.elements) {
        if (temp == 0) {
            part1 = i.first;
            charge2 = i.second;
            temp = 1;
        }
        else {
            part2 = i.first;
            charge1 = i.second;
        }
    }
    temp = 0;
    for (auto i : reactant2->getMaterial()->formula.elements) {
        if (temp == 0) {
            part3 = i.first;
            charge4 = i.second;
            temp = 1;
        }
        else {
            part4 = i.first;
            charge3 = i.second;
        }
    }
    if (part2.empty() && part4.empty()) {
        return synthesis(part1, charge1, part3, charge3, reactant1, reactant2);
    }
    else if (part2.empty()) {
        return singleReaction(part1, charge1, part3, charge3, part4, charge4, reactant1, reactant2);
        //set products
    }
    else if (part4.empty()) {
        return singleReaction(part3, charge3, part1, charge1, part2, charge2, reactant1, reactant2);
    }
    else {
        return doubleReaction(part1, charge1, part2, charge2, part3, charge3, part4, charge4, reactant1, reactant2);
    }
}

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

void ChemistryHelper::balanceEquation(ChemicalEquation* equation) {
    std::map<std::string, int> reactantAmts;
    std::map<std::string, int> productAmts;

    for (auto& reactant : equation->reactants) {
        for (auto i = reactant.first->formula.elements.begin(); i != reactant.first->formula.elements.end(); i++) {
            reactantAmts[i->first] += i->second * reactant.second;
        }
    }
    for (auto& product : equation->products) {
        for (auto i = product.first->formula.elements.begin(); i != product.first->formula.elements.end(); i++) {
            productAmts[i->first] += i->second * product.second;
        }
    }
    for (auto it = equation->reactants.begin(); it != equation->reactants.end(); it++) {
        for (auto i = it->first->formula.elements.begin(); i != it->first->formula.elements.end(); i++) {
            if (reactantAmts[i->first] != productAmts[i->first]){
                if(reactantAmts[i->first] > productAmts[i->first]){
                    for (auto it2 = equation->products.begin(); it2 != equation->products.end(); it2++) {
                        if (it2->first->formula.elements.count(i->first) > 0) {
                            if(((equation->products[it2->first]) % 2) != 0){
                                equation->products[it2->first]++;
                            }
                            else{
                                equation->products[it2->first]*=2;
                            }
                        }
                    }
                }
                else if(reactantAmts[i->first] < productAmts[i->first]){
                    for (auto it2 = equation->reactants.begin(); it2 != equation->reactants.end(); it2++) {
                        if (it2->first->formula.elements.count(i->first) > 0) {
                            if(((equation->reactants[it2->first]) % 2) != 0){
                                equation->reactants[it2->first]++;
                            }
                            else{
                                equation->reactants[it2->first]*=2;
                            }
                        }
                    }
                }
                bool divisible=true;
                for (auto& reactant : equation->reactants) {
                    if (reactant.second%2!=0){
                        divisible = false;
                    }
                }
                for (auto& product : equation->products) {
                    if (product.second%2!=0){
                        divisible = false;
                    }
                }
                if(divisible){
                    for (auto& reactant : equation->reactants) {
                        reactant.second/=2;
                    }
                    for (auto& product : equation->products) {
                        product.second/=2;
                    }
                }
                balanceEquation(equation);
            }
            else{
                return;
            }
        }
    }
}

