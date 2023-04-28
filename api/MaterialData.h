#include <map>
#include <string>
#include <utility>

class MaterialData {
public:
    static std::map<std::string, MaterialData*> FLUIDS;
    static void initFluids();

    const std::string name;
private:
    // TODO: make this take in various stats about the fluid (like name)
    MaterialData(std::string  name) : name(std::move(name)) {};
    void init();
};