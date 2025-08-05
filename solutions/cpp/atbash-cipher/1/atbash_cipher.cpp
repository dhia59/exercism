#include "atbash_cipher.h"
#include <iostream>
#include <string>
namespace atbash_cipher {

// TODO: add your solution here

    //(s+e)-x
std::string encode(std::string s) {
	std::string plain = "abcdefghijklmnopqrstuvwxyz";//97-122
	std::string cipher = "zyxwvutsrqponmlkjihgfedcba";
	std::string outerff = "";
	std::string res = "";
	std::size_t j = 0;
	while (j < s.length()) {
		int count = 1;
		while (j < s.length() && count <= 5) {
			if (s[j] >= 97 && s[j] <= 122) {
				outerff += static_cast<char>(219 - s[j]);
				count++;
			}
			else if (s[j] >= 65 && s[j] <= 90) {
				outerff += static_cast<char>(219 - s[j] - 32);
				count++;
			}
			else if (s[j] >= 48 && s[j] <= 57) {
				outerff += s[j];
				count++;
			}
			j++;
		}
		outerff += " ";
	}
	
	while (!outerff.empty() && outerff.back() == ' ') {
		outerff.pop_back();
	}

	return outerff;
}

    std::string decode(std::string s){

        
        std::string out="";
        for(std::size_t i=0;i<s.length();i++){
            if(s[i]>=48 && s[i]<=57){
                  out+=s[i];
                }
            else if(s[i]!=' '){
                out+=static_cast<char>(219-s[i]);
            }
        }
        return out;
    }
}  // namespace atbash_cipher
