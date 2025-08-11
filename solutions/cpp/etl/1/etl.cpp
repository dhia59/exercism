#include "etl.h"

namespace etl {

// TODO: add your solution here

    std::map<char,int> transform(std::map<int, std::vector<char>> old){
        std::map<char,int> newmap;
        for(auto old_el : old){
            for(auto old_el_vect_el : old_el.second){
                newmap[old_el_vect_el+32]=old_el.first;
            }
        }
        return newmap;
    }
}  // namespace etl
