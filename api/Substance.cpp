//
// Created by Malcolm Roalson on 4/28/23.
//

#include "Substance.h"
#include <fstream>
#include <string>

bool Substance::operator==(const Substance& other) const {
    return volume == other.volume;
}

int Substance::getVolume() const {
    return volume;
}

void Substance::setVolume(int v) {
    volume = v;
}

MaterialData* Substance::getMaterial() const {
    return material;
}

void Substance::setMaterial(MaterialData* mat) {
    material = mat;
}

Substance::State Substance::getState() const {
    return state;
}

void Substance::setState(State state) {
    this->state = state;
}

//performs phaseChange depending on the temperature and melting/boiling point of the substance
//@param temperature int
//@return State (enum) for the substance
Substance::State Substance::phaseChange (int temp) {
    std::ifstream newfile ("Reactants.csv");
    std::string line;
    int MP = 0, BP = 0;
    if (newfile.is_open()) {
        getline(newfile, line);
        while (getline(newfile, line)) {
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ',') {
                    if(material->form.toStdString() == line.substr(1, i - 2)) {
                        MP = stoi(line.substr(i+1, (line.find('|')-(i+1))));
                        BP = stoi(line.substr((line.find('|')+1),(line.length()-line.find('|'))));
                    }
                }
            }
        }
        newfile.close();
    }
    if(temp <= MP) {return SOLID;}
    else if (temp >= BP) {return GAS;}
    else {return LIQUID;}
}