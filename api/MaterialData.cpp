#include "MaterialData.h"

std::map<std::string, MaterialData*> MaterialData::SUBSTANCES = {};
std::vector<MaterialData*> MaterialData::REACTANTS = {};
std::map<std::string, std::string> MaterialData::FORMULAS = {};

void MaterialData::initFluids() {
    //reactants
    (new MaterialData("Sodium", "red", "Na", MaterialFormula({{"Na", 1}}), 22.99, 0.968, CompoundType::CATION,0,26.06))->reactant()->init();
    (new MaterialData("Chlorine", "orange","Cl2", MaterialFormula({{"Cl", 2}}), 70.9, 3.2, CompoundType::ANION,0,223.08))->reactant()->init();
    (new MaterialData("Calcium", "yellow", "Ca", MaterialFormula({{"Ca", 1}}), 40.078, 1.55, CompoundType::CATION,0,154.89))->reactant()->init();
    (new MaterialData("Fluorine", "green", "F2",MaterialFormula({{"F", 2}}), 37.997, 1.69, CompoundType::ANION,0,202.8))->reactant()->init();
    (new MaterialData("Sodium Chloride", "purple", "NaCl", MaterialFormula({{"Na", 1}, {"Cl", 1}}), 58.440, 2.16, CompoundType::IONIC,787,72))->reactant()->init();
    (new MaterialData("Calcium Fluoride", "pink", "CaF2", MaterialFormula({{"Ca", 1}, {"F", 2}}), 78.074, 3.18, CompoundType::IONIC,-1220,-46.34))->reactant()->init();

    //products
    (new MaterialData("Sodium Fluoride", "cyan", "NaF", MaterialFormula({{"Na", 1}, {"F", 1}}), 41.988, 2.56, CompoundType::IONIC,-546.2,73.46))->init();
    (new MaterialData("Calcium Chloride", "brown", "CaCl2", MaterialFormula({{"Ca", 1}, {"Cl", 2}}), 110.98, 2.15, CompoundType::IONIC,-774.09,123.87))->init();
}

void MaterialData::init() {
    SUBSTANCES[formula.toString().toStdString()] = this;
    FORMULAS[name] = formula.toString().toStdString();
}

MaterialData* MaterialData::reactant() {
    REACTANTS.push_back(this);
    return this;
}