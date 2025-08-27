#include "sublist.h"

namespace sublist {

// TODO: add your solution here
List_comparison sublist(std::vector<int> a,std::vector<int> b){
    std::vector<int>* longestlist;
    std::vector<int>* shortestlist;
    if(b.size() > a.size()){
        longestlist=&b;
        shortestlist=&a;
    }else{
         longestlist=&a;
        shortestlist=&b;
    }
    if(b.size() == a.size()){
        for(size_t i=0; i<a.size();i++){
            if(a[i]!=b[i]) return List_comparison::unequal;
        }
        return List_comparison::equal;
    }
    for(size_t i=0; i<=((*longestlist).size()-(*shortestlist).size());i++){
        bool eq=true;
        for(size_t j=i; j<((*shortestlist).size()+i);j++){
            std::cout << "from " << i << " to => " << (*shortestlist).size() + i
                  << ": " << (*shortestlist)[j - i] << "==" << (*longestlist)[j] << " eq = "<<eq<<  std::endl;

            if ((*shortestlist)[j - i] != (*longestlist)[j]) {
                eq = false;
                            }

        }

        if(eq){
            
            if(b.size() > a.size())
                 return List_comparison::sublist;
             else
                return List_comparison::superlist;
        }
    }

     return List_comparison::unequal;
 }
}  // namespace sublist
