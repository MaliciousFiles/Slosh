#include <map>
#include <string>
#include <utility>

class MaterialData {
public:
    static std::map<std::string, MaterialData*> FLUIDS;
    static void initFluids();

    const std::string name;
    const double density; // g/mL (or g/cm^3)
    const double molarMass; // g/mol
    const double enthalpyFormation; // kJ/mol (liquid)
    const double entropy; // J/mol*K (liquid)
private:
    MaterialData(std::string name, double density, double molarMass, double enthalpyFormation, double entropy) : name(std::move(name)), density(density), molarMass(molarMass), enthalpyFormation(enthalpyFormation), entropy(entropy) {};
    void init();
};