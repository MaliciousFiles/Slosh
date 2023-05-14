#include "MaterialData.h"

std::map<MaterialFormula, MaterialData*> MaterialData::SUBSTANCES = {};

void MaterialData::initFluids() {
    // TODO: read from a file or something
    (new MaterialData("Water", "blue", "H2O", MaterialFormula({{"H", 2}, {"O", 1}}), 18.015, CompoundType::POLAR_COVALENT,-286,16.8))->init();

    //reactants
    (new MaterialData("Sodium", "red", "Na", MaterialFormula({{"Na", 1}}), 22.99, CompoundType::CATION,0,26.06))->init();
    (new MaterialData("Chlorine", "orange","Cl2", MaterialFormula({{"Cl", 2}}), 70.9, CompoundType::ANION,0,223.08))->init();
    (new MaterialData("Calcium", "yellow", "Ca", MaterialFormula({{"Ca", 1}}), 40.078, CompoundType::CATION,0,154.89))->init();
    (new MaterialData("Fluorine", "green", "F2",MaterialFormula({{"F", 2}}), 37.997, CompoundType::ANION,0,202.8))->init();
    (new MaterialData("Sodium Chloride", "purple", "NaCl", MaterialFormula({{"Na", 1}, {"Cl", 1}}), 58.440, CompoundType::IONIC,787,72))->init();
    (new MaterialData("Calcium Fluoride", "pink", "CaF2", MaterialFormula({{"Ca", 1}, {"F", 2}}), 78.074, CompoundType::IONIC,-1220,-46.34))->init();

    //products
    (new MaterialData("Sodium Chloride", "purple", "NaCl", MaterialFormula({{"Na", 1}, {"Cl", 1}}), 58.440, CompoundType::IONIC,0,0))->init();
    (new MaterialData("Calcium Fluoride", "pink", "CaF2", MaterialFormula({{"Ca", 1}, {"F", 2}}), 78.074, CompoundType::IONIC,0,0))->init();
    (new MaterialData("Sodium Fluoride", "cyan", "NaF", MaterialFormula({{"Na", 1}, {"F", 1}}), 41.988, CompoundType::IONIC,0,0))->init();
    (new MaterialData("Calcium Chloride", "brown", "CaCl2", MaterialFormula({{"Ca", 1}, {"Cl", 2}}), 110.98, CompoundType::IONIC,0,0))->init();
    (new MaterialData("Sodium", "red", "Na", MaterialFormula({{"Na", 1}}), 22.99, CompoundType::CATION,0,0))->init();
    (new MaterialData("Chlorine", "orange", "Cl2", MaterialFormula({{"Cl", 2}}), 70.9, CompoundType::ANION,0,0))->init();
    (new MaterialData("Calcium", "yellow", "Ca", MaterialFormula({{"Ca", 1}}), 40.078, CompoundType::CATION,0,0))->init();
    (new MaterialData("Fluorine", "green", "F2", MaterialFormula({{"F", 2}}), 37.997, CompoundType::ANION,0,0))->init();
}

void MaterialData::init() {
    SUBSTANCES[formula] = this;
}