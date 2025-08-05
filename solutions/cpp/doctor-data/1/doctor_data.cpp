// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#include "doctor_data.h"



    std::string heaven::get_older_bob(Vessel v1,Vessel v2){
        if(v1.generation<v2.generation) return v1.name;
        else return v2.name;
    }

    bool heaven::in_the_same_system(Vessel v1,Vessel v2){
        return v1.current_system==v2.current_system;
    }