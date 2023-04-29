//
// Created by Malcolm Roalson on 4/28/23.
//

#ifndef SLOSH_SUBSTANCE_H
#define SLOSH_SUBSTANCE_H


#include <utility>

#include "MaterialData.h"

class Substance {

public:
    explicit Substance(MaterialData* material, int volume) : material(material), volume(volume) {}

    bool operator==(const Substance& other) const;

    int getVolume() const;
    void setVolume(int v);
    MaterialData* getMaterial() const;
    void setMaterial(MaterialData* mat);

private:
    int volume;
    MaterialData* material;
};


#endif //SLOSH_SUBSTANCE_H
