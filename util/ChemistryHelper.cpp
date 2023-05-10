//
// Created by Malcolm Roalson on 4/28/23.
//

#include "ChemistryHelper.h"
#include <fstream>
#include <string>

std::string ChemistryHelper::singleReaction(std::string one, std::string three, std::string four) {
    ifstream myfile ("Elements.csv");
    string line;
    string temp1, temp3;
    int temp2;
    int charge1, charge3, charge4;
    string ion;
    if (myfile.is_open()) {
        getline(myfile, line);
        while (getline(myfile, line)) {
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ',') {
                    temp1 = line.substr(1, i - 2);
                    temp2 = stoi((line.substr(i + 1, 1)));
                    temp3 = line.substr(i+3,6);
                }
            }
            if (one == temp1) {
                charge1 = temp2;
                ion = temp3;
            }
            if (three == temp1) {
                charge3 = temp2;
            }
            if (four == temp1) {
                charge4 = temp2;
            }
        }
        myfile.close();
    }
    std::string product1;
    std::string product2;
    if (ion == "cation") {
        if(charge4 == 1 && charge1 == 1) {
            product1 = one + four;
        }
        else if (charge4 == 1) {
            product1 = one + four + to_string(charge1);
        }
        else if (charge1 == 1) {
            product1 = one + to_string(charge4) + four;
        }
        else {
            product1 = one + to_string(charge4) + four + to_string(charge1);
        }
        product2 = three;
    }
    else {
        if(charge3 == 1 && charge1 == 1) {
            product1 = three + one;
        }
        else if (charge3 == 1) {
            product1 = three + to_string(charge1) + one;
        }
        else if (charge1 == 1) {
            product1 = three + one + to_string(charge3);
        }
        else {
            product1 = three + to_string(charge1) + one + to_string(charge3);
        }
        product2 = four;
    }
    return product1 + " " + product2;
}

ChemicalEquation* ChemistryHelper::products(Substance* reactant1, Substance* reactant2) {
    std::string temp1 = reactant1->getMaterial()->formula;
    std::string part1;
    std::string part2;
    for (int s = 0; s < temp1.length(); s++) {
        part1+=temp1[s];
        if ((int)temp1[s] < 58 || (int)temp1[s] > 96) {
            if ((int)temp1[s+1]<58) {
                part1+=temp1[s+1];
                if (s != temp1.length()-1) {
                    for (int t = s+1; t < temp1.length(); t++) {
                        part2+=temp1[t];
                        if ((int)temp1[t] > 96) {
                            break;
                        }
                    }
                }
                break;
            }
            if (s != temp1.length()-1) {
                for (int t = s+1; t < temp1.length(); t++) {
                    part2+=temp1[t];
                    if ((int)temp1[t] > 96) {
                        break;
                    }
                }
            }
            break;
        }
    }
    std::string temp2 = reactant2->getMaterial()->formula;
    std::string part3;
    std::string part4;
    for (int s = 0; s < temp2.length(); s++) {
        part3+=temp2[s];
        if ((int)temp2[s] < 58 || (int)temp2[s] > 96) {
            if ((int)temp2[s+1]<58) {
                part3+=temp2[s+1];
                if (s != temp2.length()-1) {
                    for (int t = s+1; t < temp2.length(); t++) {
                        part4+=temp2[t];
                        if ((int)temp2[t] > 96) {
                            break;
                        }
                    }
                }
                break;
            }
            if (s != temp2.length()-1) {
                for (int t = s+1; t < temp2.length(); t++) {
                    part4+=temp2[t];
                    if ((int)temp2[t] > 96) {
                        break;
                    }
                }
            }
            break;
        }
    }
    std::string reactionType;
    if (part2.empty()) {
        singleReaction(part1, part3, part4);
    }
    else if (part4.empty()) {
        singleReaction(part3, part1, part2);
    }
    else {
        reactionType = "double";
    }
    Substance* product1;
    Substance* product2;
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

    for (std::map<MaterialData*, int>::iterator it = equation->reactants.begin(); it != equation->reactants.end(); it++) {
        for (std::map<std::string, int>::iterator i = it->first->formula.elements.begin(); i != it->first->formula.elements.end(); i++) {
            reactantAmts[i->first] += i->second * it->second;
        }
    }
    for (std::map<MaterialData*, int>::iterator it = equation->products.begin(); it != equation->products.end(); it++) {
        for (std::map<std::string, int>::iterator i = it->first->formula.elements.begin(); i != it->first->formula.elements.end(); i++) {
            productAmts[i->first] += i->second * it->second;
        }
    }
    for (std::map<MaterialData*, int>::iterator it = equation->reactants.begin(); it != equation->reactants.end(); it++) {
        for (std::map<std::string, int>::iterator i = it->first->formula.elements.begin(); i != it->first->formula.elements.end(); i++) {
            if (reactantAmts[i->first] != productsAmts[i->first]){
                if(reactantAmts[i->first] > productsAmts[i->first]){
                    for (std::map<MaterialData*, int>::iterator it = equation->products.begin(); it != equation->products.end(); it++) {
                        if (it->first->formula.elements.count(i->first) > 0) {
                            if(((equation->products[it->first])%2)!=0){
                                equation->products[it->first]++;
                            }
                            else{
                                equation->products[it->first]*=2;
                            }
                        }
                    }
                }
                else if(reactantAmts[i->first] < productsAmts[i->first]){
                    for (std::map<MaterialData*, int>::iterator it = equation->reactants.begin(); it != equation->reactants.end(); it++) {
                        if (it->first->formula.elements.count(i->first) > 0) {
                            if(((equation->reactants[it->first])%2)!=0){
                                equation->reactants[it->first]++;
                            }
                            else{
                                equation->reactants[it->first]*=2;
                            }
                        }
                    }
                }
                bool divisible=true;
                for (std::map<MaterialData*, int>::iterator it = equation->reactants.begin(); it != equation->reactants.end(); it++) {
                    if (it->second%2!=0){
                        divisible = false;
                    }
                }
                for (std::map<MaterialData*, int>::iterator it = equation->products.begin(); it != equation->products.end(); it++) {
                    if (it->second%2!=0){
                        divisible = false;
                    }
                }
                if(divisible){
                    for (std::map<MaterialData*, int>::iterator it = equation->reactants.begin(); it != equation->reactants.end(); it++) {
                        it->second/=2;
                    }
                    for (std::map<MaterialData*, int>::iterator it = equation->products.begin(); it != equation->products.end(); it++) {
                        it->second/=2;
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

