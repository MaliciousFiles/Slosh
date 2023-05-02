//
// Created by Malcolm Roalson on 4/28/23.
//

#include "Container.h"

void Container::addSubstance(Substance* substance) {
    substances.push_back(substance);

}

void Container::removeSubstance(Substance* substance) {
    substances.erase(std::remove(substances.begin(), substances.end(), substance), substances.end());
}

Substance* Container::getSubstance(MaterialData* material) {
    return *std::find_if(substances.begin(), substances.end(),
                                      [material](Substance* s){
                                                return s->getMaterial() == material;
    });
}

void Container::setTemperature(double temp) {
    temperature = temp;
}

double Container::getTemperature() const {
    return temperature;
}

int Container::getVolume() const {
    return volume;
}

int Container::getFilledVolume() {
    int o = 0;
    for (auto &substance : substances) o += substance->getVolume();
    return o;
}