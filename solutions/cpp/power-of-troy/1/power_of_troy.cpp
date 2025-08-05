#include "power_of_troy.h"

namespace troy {

    



void give_new_artifact(human& p, const std::string& s) {
    p.possession = std::make_unique<artifact>(s);
}


void exchange_artifacts(std::unique_ptr<artifact>& a1, std::unique_ptr<artifact>& a2) {
    std::unique_ptr<artifact> tmp = std::move(a1);  // move a1 into tmp
    a1 = std::move(a2);                            // move a2 into a1
    a2 = std::move(tmp);                           // move tmp into a2
}


    void manifest_power(human& p , std::string s){
        p.own_power =std::make_shared<power>(s);
    }

    void use_power(human& h1, human& h2){
        h2.influenced_by=h1.own_power;
    }

    int power_intensity(human& h){
        return h.own_power.use_count();
    }
}  // namespace troy
