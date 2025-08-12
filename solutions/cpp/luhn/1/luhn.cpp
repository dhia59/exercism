#include "luhn.h"

namespace luhn {

// TODO: add your solution here

    bool valid(std::string input){
        if (input.length()<2) return false;
        int sum=0;
        int count=0;
        for(int i=input.length()-1;i>=0;i--){
            char c=input[i];
            if(isdigit(c)){
                
               
                if(count%2==0){
                    sum+=(c-48);
                }
                else{
                    if(c==9+48) {sum+=9;}
                    else {sum+=(((c-48)*2)%9);}
                }
                
            }else if(c==' ') continue;
            else return false;
             count++;
        }
        
        return (sum%10)==0  && count>1;
    }

    bool isdigit(char c){
        if(c>=48 && c<=57) return true;
        return false;
    }
}  // namespace luhn
