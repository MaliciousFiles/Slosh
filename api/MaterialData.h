#ifndef SLOSH_MATERIALDATA_H
#define SLOSH_MATERIALDATA_H

#include <map>
#include <string>
#include <utility>
#include "MaterialFormula.h"

class MaterialData {
public:
    static std::map<std::string, MaterialData*> FLUIDS;
    static void initFluids();

    enum CompoundType {
        POLAR_COVALENT,
        NONPOLAR_COVALENT,
        IONIC
    };

    const std::string name;
    const MaterialFormula formula;
    const double molarMass;
    const CompoundType compound;
private:
    // TODO: make this take in various stats about the fluid (like name)
    MaterialData(std::string  name, MaterialFormula formula, double molarMass, CompoundType compound) : name(std::move(name)), formula(std::move(formula)), molarMass(std::move(molarMass)), compound(std::move(compound)) {};
    void init();
};

#endif // SLOSH_MATERIALDATA_H