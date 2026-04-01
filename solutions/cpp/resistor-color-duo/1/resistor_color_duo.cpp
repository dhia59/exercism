#include "resistor_color_duo.h"
#include <unordered_map>
namespace resistor_color_duo {

// TODO: add your solution here
    int getval(std::string color){
    static const std::unordered_map<std::string, int> table {
        {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3},
        {"yellow", 4}, {"green", 5}, {"blue", 6},
        {"violet", 7}, {"grey", 8}, {"white", 9}
    };

    
    
        return table.at(color); // throws if not found
    }
 int value(std::vector<std::string> input){
    int val=0;
    
    val=getval(input[0])*10+getval(input[1]);
     
    return val;
 }


    
}  // namespace resistor_color_duo
