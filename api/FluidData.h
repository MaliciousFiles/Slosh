#include <map>
#include <string>
#include <utility>

class FluidData {
public:
    static std::map<std::string, FluidData*> FLUIDS;
    static void initFluids();

    const std::string name;
private:
    // TODO: make this take in various stats about the fluid (like name)
    FluidData(std::string  name) : name(std::move(name)) {};
    void init();
};