#include "MaterialData.h"

std::map<std::string, MaterialData*> MaterialData::FLUIDS = {};

void MaterialData::initFluids() {
    (new MaterialData("Water", QColor(88, 165, 237), MaterialFormula({{"H", 2}, {"O", 1}}), 18.015, CompoundType::POLAR_COVALENT, 0, 0))->init();
    (new MaterialData("Sodium Chloride", QColor(240, 240, 125), MaterialFormula({{"Na", 1}, {"Cl", 1}}), 58.440, CompoundType::IONIC, 0, 0))->init();
    (new MaterialData("Calcium Fluoride", QColor(184, 124, 214), MaterialFormula({{"Ca", 1}, {"F", 2}}), 78.074, CompoundType::IONIC, 0, 0))->init();
    (new MaterialData("Oxygen", QColor(174, 245, 252), MaterialFormula({{"O", 2}}), 31.998, CompoundType::NONPOLAR_COVALENT, 0, 0))->init();
    (new MaterialData("Carbon Dioxide", QColor(175, 219, 116), MaterialFormula({{"C", 1}, {"O", 2}}), 44.009, CompoundType::NONPOLAR_COVALENT, 0, 0))->init();
}

void MaterialData::init() {
    FLUIDS[name] = this;
}