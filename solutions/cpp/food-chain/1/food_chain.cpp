#include "food_chain.h"

namespace food_chain {

// TODO: add your solution here
std::string matrix[8][3] = {
    {"fly", "","I don't know why she swallowed the fly. Perhaps she'll die.\n"},
    {"spider", "It wriggled and jiggled and tickled inside her.\n" , "She swallowed the spider to catch the fly.\n" },
    {"bird", "How absurd to swallow a bird!\n","She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n"},
    {"cat", "Imagine that, to swallow a cat!\n","She swallowed the cat to catch the bird.\n"},
    {"dog", "What a hog, to swallow a dog!\n","She swallowed the dog to catch the cat.\n"},
    {"goat", "Just opened her throat and swallowed a goat!\n","She swallowed the goat to catch the dog.\n"},
    {"cow", "I don't know how she swallowed a cow!\n","She swallowed the cow to catch the goat.\n"},
    {"horse", "She's dead, of course!\n",""}
};
       // Surcharge pour un seul int
    std::string verse(int v) {
            std::string result="";
    
               if(v==8){
                   result+="I know an old lady who swallowed a "+matrix[v-1][0]+".";
                     result+="\n";
                   result+=matrix[v-1][1];
                   return result;
               }
               result+="I know an old lady who swallowed a "+matrix[v-1][0]+".";
               result+="\n";
               if(matrix[v-1][1].length()>0){
                   result+=matrix[v-1][1];
               }
               for(int i=v-1;i>=0;i--){
                   result+=matrix[i][2];
               }
            
               
            
       
            return result;
    }

    // Surcharge pour deux int
    std::string verses(int a, int b) {
        return verse(a)+"\n"+verse(b)+"\n";
        
    }

   std::string sing(){
       std::string lyrics =
        "I know an old lady who swallowed a fly.\n"
        "I don't know why she swallowed the fly. Perhaps she'll die.\n\n"
        "I know an old lady who swallowed a horse.\n"
        "She's dead, of course!\n\n";

       return lyrics;
   } 
    
}  // namespace food_chain
