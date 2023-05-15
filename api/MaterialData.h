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
    static std::map<std::string, std::string> FORMULAS;
    static std::vector<MaterialData*> REACTANTS;
    static void initFluids();

    enum CompoundType {
        POLAR_COVALENT,
        NONPOLAR_COVALENT,
        IONIC,
        ANION,
        CATION
    };

    const std::string name;
    const QString form;
    const MaterialFormula formula;
    const double molarMass;
    const double density; // g/cm^3
    const CompoundType compound;
    const double enthalpyFormation;
    const double entropy;
    const QColor color;
private:
    MaterialData(std::string name, QColor color, QString form, MaterialFormula formula, double molarMass, double density, CompoundType compound, double enthalpyFormation, double entropy) : name(std::move(name)), color(color), form(std::move(form)), formula(std::move(formula)), molarMass(molarMass), density(density), compound(compound), enthalpyFormation(enthalpyFormation), entropy(entropy) {};
    void init();
    MaterialData* reactant();
};

#endif // SLOSH_MATERIALDATA_H