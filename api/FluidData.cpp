#include "FluidData.h"

std::map<std::string, FluidData*> FluidData::FLUIDS = {};

void FluidData::initFluids() {
    // TODO: read from a file or something
    (new FluidData("Water"))->init();
    (new FluidData("Oil"))->init();
    (new FluidData("Ammonia Nitrate"))->init();
}

void FluidData::init() {
    FLUIDS[name] = this;
}