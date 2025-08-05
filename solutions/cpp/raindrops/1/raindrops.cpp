#include "raindrops.h"

namespace raindrops {

std::string convert (int number){
    std::string res="";
    bool tostring=true;
    if((number % 3)==0 ){
        res =res+"Pling";
        tostring=false;
    }
    if((number % 5)==0 ){
        res =res+"Plang";
        tostring=false;
    }
    if((number % 7)==0 ){
        res =res+"Plong";
        tostring=false;
    }

    if(tostring)
        res = std::to_string(number);

    return res;
}

}  // namespace raindrops
