#include "MaterialData.h"

std::map<std::string, MaterialData*> MaterialData::FLUIDS = {};

void MaterialData::initFluids() {
    // TODO: read from a file or something
    (new MaterialData("Water", MaterialFormula({{"H", 2}, {"O", 1}}), 18.015, CompoundType::POLAR_COVALENT))->init();
    (new MaterialData("Sodium Chloride", MaterialFormula({{"Na", 1}, {"Cl", 1}}), 58.440, CompoundType::IONIC))->init();
    (new MaterialData("Calcium Fluoride", MaterialFormula({{"Ca", 1}, {"F", 2}}), 78.074, CompoundType::IONIC))->init();
    (new MaterialData("Oxygen", MaterialFormula({{"O", 2}}), 31.998, CompoundType::NONPOLAR_COVALENT))->init();
    (new MaterialData("Carbon Dioxide", MaterialFormula({{"C", 1}, {"O", 2}}), 44.009, CompoundType::NONPOLAR_COVALENT))->init();
}

void MaterialData::init() {
    FLUIDS[name] = this;
}