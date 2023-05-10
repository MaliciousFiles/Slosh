#include <map>
#include <string>
#include <utility>

class MaterialData {
public:
    static std::map<std::string, MaterialData*> FLUIDS;
    static void initFluids();

    const std::string name;
    const std::string formula;
    const int molarmass;
    const std::string compound;
private:
    // TODO: make this take in various stats about the fluid (like name)
    MaterialData(std::string  name, std::string formula, int molarmass, std::string compound) : name(std::move(name)), formula(std::move(formula)), molarmass(std::move(molarmass)), compound(std::move(compound)) {};
    void init();
};