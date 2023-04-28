#include "MaterialData.h"

std::map<std::string, MaterialData*> MaterialData::FLUIDS = {};

void MaterialData::initFluids() {
    // TODO: read from a file or something
    (new MaterialData("Water"))->init();
    (new MaterialData("Oil"))->init();
    (new MaterialData("Ammonia Nitrate"))->init();
}

void MaterialData::init() {
    FLUIDS[name] = this;
}