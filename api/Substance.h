//
// Created by Malcolm Roalson on 4/28/23.
//

#ifndef SLOSH_SUBSTANCE_H
#define SLOSH_SUBSTANCE_H


#include <utility>

#include "MaterialData.h"

class Substance {

public:
    enum State {
        SOLID,
        LIQUID,
        GAS,
        AQUEOUS
    };

    explicit Substance(MaterialData* material, int volume, State state) : material(material), volume(volume), state(state) {}

    bool operator==(const Substance& other) const;

    int getVolume() const;
    void setVolume(int v);
    MaterialData* getMaterial() const;
    void setMaterial(MaterialData* mat);
    State getState() const;
    void setState(State state);

private:
    int volume;
    State state;
    MaterialData* material;
};


#endif //SLOSH_SUBSTANCE_H
