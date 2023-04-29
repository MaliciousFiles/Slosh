//
// Created by Malcolm Roalson on 4/28/23.
//

#ifndef SLOSH_CONTAINER_H
#define SLOSH_CONTAINER_H

#include "Substance.h"
#include <vector>

class Container {

public:
    const int volume;
    explicit Container(int volume) : volume(volume) {}

    void addSubstance(Substance* substance);
    void removeSubstance(Substance* substance);
    Substance* getSubstance(MaterialData* material);
    int getVolume() const;
    int getFilledVolume();

private:
    std::vector<Substance*> substances;
};


#endif //SLOSH_CONTAINER_H
