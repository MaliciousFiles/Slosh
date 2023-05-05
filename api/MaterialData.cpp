#include "MaterialData.h"

std::map<std::string, MaterialData*> MaterialData::FLUIDS = {};

void MaterialData::initFluids() {
    // TODO: read from a file or something
    (new MaterialData("Water", 1, 33.006, -285.83, 69.95))->init();
//    (new MaterialData("Oil", 0, 0))->init();
    (new MaterialData("Phosphoric Acid", 1.88, 97.994, -1271.66, 150.77))->init();
}

void MaterialData::init() {
    FLUIDS[name] = this;
}