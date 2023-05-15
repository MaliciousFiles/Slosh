#ifndef SLOSH_MATERIALDATA_H
#define SLOSH_MATERIALDATA_H

#include <QColor>
#include <map>
#include <string>
#include <utility>
#include "MaterialFormula.h"

class MaterialData {
public:
    static std::map<std::string, MaterialData*> SUBSTANCES;
    static void initFluids();

    enum CompoundType {
        POLAR_COVALENT,
        NONPOLAR_COVALENT,
        IONIC,
        ANION,
        CATION
    };

    const std::string name;
    const std::string form;
    const MaterialFormula formula;
    const double molarMass;
    const CompoundType compound;
    const double enthalpyFormation;
    const double entropy;
    const QColor color;
private:
    // TODO: make this take in various stats about the fluid (like name)
    MaterialData(std::string name, QColor color, std::string form, MaterialFormula formula, double molarMass, CompoundType compound, double enthalpyFormation, double entropy) : name(std::move(name)), color(std::move(color)), form(std::move(form)), formula(std::move(formula)), molarMass(std::move(molarMass)), compound(std::move(compound)), enthalpyFormation(enthalpyFormation), entropy(entropy) {};
    void init();
};

#endif // SLOSH_MATERIALDATA_H