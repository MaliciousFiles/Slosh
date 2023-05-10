#include "MaterialData.h"

std::map<std::string, MaterialData*> MaterialData::FLUIDS = {};

void MaterialData::initFluids() {
    // TODO: read from a file or something
    (new MaterialData("Water", "H2O", 18.015, "polar covalent"))->init();
    (new MaterialData("Sodium Chloride", "NaCl", 58.440, "ionic"))->init();
    (new MaterialData("Calcium Fluoride", "CaF2", 78.074, "ionic"))->init();
    (new MaterialData("Oxygen", "O2", 31.998, "nonpolar covalent"))->init();
    (new MaterialData("Carbon Dioxide", "CO2", 44.009, "nonpolar covalent"))->init();
}

void MaterialData::init() {
    FLUIDS[name] = this;
}