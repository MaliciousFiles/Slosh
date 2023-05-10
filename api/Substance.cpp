//
// Created by Malcolm Roalson on 4/28/23.
//

#include "Substance.h"

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

std::string Substance::getState() const {
    return state;
}

void Substance::setState(std::string sta) {
    state = sta;
}
