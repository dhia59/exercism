#pragma once
#include <string>

namespace star_map {
    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven {

class Vessel {
public:
    std::string name;
    int generation{0};
    star_map::System current_system{star_map::System::Sol}; // OK car System est défini avant
    int busters{0};

    Vessel(std::string name, int generation)
        : name(std::move(name)), generation(generation) {}

    Vessel(std::string name, int generation, star_map::System current_system)
        : name(std::move(name)), generation(generation), current_system(current_system) {}

    Vessel replicate(std::string name) {
        Vessel c(std::move(name), generation);
        c.current_system = current_system;
        c.generation++;
        return c;
    }

    void make_buster() {
        busters++;
    }

    bool shoot_buster() {
        if (busters <= 0) return false;
        busters--;
        return true;
    }
};

std::string get_older_bob(Vessel v1, Vessel v2);
bool in_the_same_system(Vessel v1, Vessel v2);

}
