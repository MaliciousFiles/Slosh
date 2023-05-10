//
// Created by Malcolm Roalson on 4/28/23.
//

#ifndef SLOSH_SUBSTANCE_H
#define SLOSH_SUBSTANCE_H


#include <utility>

#include "MaterialData.h"

class Substance {

public:
    explicit Substance(MaterialData* material, int volume, std::string state) : material(material), volume(volume), state(state) {}

    bool operator==(const Substance& other) const;

    int getVolume() const;
    void setVolume(int v);
    MaterialData* getMaterial() const;
    void setMaterial(MaterialData* mat);
    std::string getState() const;
    void setState(std::string sta);

private:
    int volume;
    std::string state;
    MaterialData* material;
};


#endif //SLOSH_SUBSTANCE_H
