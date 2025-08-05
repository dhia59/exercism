#include "alphametics.h"

namespace alphametics {

// Trim function pour enlever les espaces au début et à la fin
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

int stringtoint(std::string s, std::map<char, int>& letter_map) {
    std::string dtringtoint = "";
    for (long unsigned int i = 0; i < s.size();i++) {
        dtringtoint += std::to_string(letter_map.at(s[i])) ;
    }
    return std::stoi(dtringtoint);
}


bool checkvalide(std::vector<int> p, std::vector<char> l, std::vector<std::string> left, std::string right) {
    
    std::map<char, int> letter_map;

    for (long unsigned int i = 0;i < l.size();i++) {
        letter_map[l[i]] = p[i];
    }
    if (letter_map.at(right[0]) == 0) return false;
    int sum=0;

    for (long unsigned int i = 0; i < left.size(); i++)
    {
        if (letter_map.at(left[i][0]) == 0) return false;
        sum += stringtoint(left[i], letter_map);
    }
       
    if (sum == stringtoint(right, letter_map)) return true;


    return false;

}
    int stringtoint2(std::string s, std::vector<int>& letter_map) {
    std::string dtringtoint = "";
    for (long unsigned int i = 0; i < s.size();i++) {
        dtringtoint += std::to_string(letter_map.at(s[i]));
    }
    //std::cout << dtringtoint << " ";
    return std::stoi(dtringtoint);
}

bool checkvalide2(const std::vector<int>& p, const std::vector<char>& l,
    const std::vector<std::string>& left, const std::string& right) {

    // Mapping des lettres vers chiffres (ASCII max = 255)
    int letter_map[256] = { 0 };
    for (size_t i = 0; i < l.size(); ++i) {
        letter_map[static_cast<unsigned char>(l[i])] = p[i];
    }



    // Vérifie que les premiers caractères de chaque mot ne sont pas mappés à 0
    if (letter_map[static_cast<unsigned char>(right[0])] == 0)
        return false;
    /*for (const auto& word : left) {
        if (letter_map[static_cast<unsigned char>(word[0])] == 0)
            return false;
    }*/

    //[static_cast<unsigned char>(word[0])]
    std::vector<int> leftsums(right.size(), 0);

    int q = 0;
	int reslen = right.size();
    for (int i = reslen-1 ; i >=0 ; i--)
    {
        for (long unsigned int j = 0; j < left.size(); j++)
        {
			int len = left[j].size();
            if (len > (reslen-i-1)) {
                leftsums[i] += letter_map[static_cast<unsigned char>(left[j][len - (reslen - i)])];
            }

        }


        if (((leftsums[i]+q) % 10) != letter_map[static_cast<unsigned char>(right[i])]) return false;
        q = (leftsums[i] + q) / 10;
    }


    return true;

}

bool checkvalide4(const std::vector<int>& p, const std::vector<char>& l,
    const std::vector<std::string>& left, const std::string& right) {

    // Mapping des lettres vers chiffres (ASCII max = 255)
    int letter_map[256] = { 0 };
    for (size_t i = 0; i < l.size(); ++i) {
        letter_map[static_cast<unsigned char>(l[i])] = p[i];
    }

    // Vérifie que les premiers caractères de chaque mot ne sont pas mappés à 0
    if (letter_map[static_cast<unsigned char>(right[0])] == 0)
        return false;
    for (const auto& word : left) {
        if (letter_map[static_cast<unsigned char>(word[0])] == 0)
            return false;
    }

    const int len = right.size();
    std::vector<int> column_sum(len, 0);

    // Calcul de la somme colonne par colonne (de droite à gauche)
    for (const auto& word : left) {
        int offset = len - word.size();
        for (size_t i = 0; i < word.size(); ++i) {
            column_sum[offset + i] += letter_map[static_cast<unsigned char>(word[i])];
        }
    }

    // Vérifie que la somme des colonnes correspond au mot résultat
    int carry = 0;
    for (int i = len - 1; i >= 0; --i) {
        int digit = column_sum[i] + carry;
        int expected = letter_map[static_cast<unsigned char>(right[i])];
        if ((digit % 10) != expected)
            return false;
        carry = digit / 10;
    }

    // Si tu veux une somme exacte sans dépassement, tu peux vérifier : if (carry != 0) return false;
    return true;
}

bool allUnique(const std::vector<int>& numbers) {
    std::set<int> seen;
    for (int n : numbers) {
        if (!seen.insert(n).second) {
            // L'insertion a échoué → doublon trouvé
            std::cout << "NOT UNIQUE: "<<std::endl;
            return false;
        }
    }
    return true;
}
bool genpermut(long unsigned int indx, std::vector<int> availabledigits, std::vector<int>& permut,
    std::vector<char>& letters, std::vector<std::string>& left, std::string& right,
    bool& founded) {

    if (founded) return true;  // ✅ Arrête la récursion dès qu'une solution est trouvée

    for (long unsigned int i = 0; i < availabledigits.size(); i++) {
        permut[indx] = availabledigits[i];

        if (indx == permut.size() - 1) {
            if (checkvalide2(permut, letters, left, right)) {
                founded = true;


                return true; // ✅ Retourne dès que trouvé
            }
        }
        else {
            std::vector<int> newavailabledigits;
            for (long unsigned int j = 0; j < availabledigits.size(); j++) {
                if (i != j) {
                    newavailabledigits.push_back(availabledigits[j]);
                }
            }

            if (genpermut(indx + 1, newavailabledigits, permut, letters, left, right, founded)) {
                return true; // ✅ Propagation du true si solution trouvée
            }
        }
    }
    return false; // ✅ Fin normale de la fonction (pas de solution trouvée)
}
    
// TODO: add your solution here
std::optional<std::unordered_map<char, int>> solve(const std::string& puzzle)
{


    std::vector<std::string> left;
    std::string right;

    // Séparer par "=="
    size_t pos = puzzle.find("==");
 

    std::string leftPart = puzzle.substr(0, pos);
    std::string rightPart = puzzle.substr(pos + 2); // ignorer les deux caractères "=="

    // Supprimer les espaces en début/fin du right
    rightPart.erase(0, rightPart.find_first_not_of(" \t"));
    rightPart.erase(rightPart.find_last_not_of(" \t") + 1);
    right = rightPart;

    std::stringstream ss(leftPart);
    std::string token;
    while (std::getline(ss, token, '+')) {
        // Supprimer les espaces autour de chaque terme
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);
        left.push_back(token);
    }

    // Affichage
    std::cout << "Left terms :" << std::endl;
  

    std::cout << "Right term: " << right << std::endl;


  
    //std::map<char, int> letter_map;
    std::vector<char> letters;

    std::cout << "letters: ";
    std::set<char> seen;

    for (char c : puzzle) {
        if (std::isalpha(c) && seen.insert(c).second) {
            letters.push_back(c);
            std::cout << c;  // Affiche uniquement les lettres uniques
        }
    }
    std::cout << std::endl;
    int n = letters.size();

   

       int must_be_not_null[10] = {0};

       for ( int i = 0;i < n;i++) {
           for (long unsigned int j = 0;j < left.size();j++) {
			   if (left[j][0] == letters[i]) {
				   must_be_not_null[i] = 1;
				   continue;
			   }
           }
       }
    //if(left.size()!=7) return std::nullopt;
    //if(left.size()!=199) return std::nullopt;
    std::vector<int> permut (n, 0);

        bool end = false;
    bool founded = false;
    std::vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };


   /* do {
        // Traitement de la permutation ici, ex :
        

        if (checkvalide2(digits, letters, left, right)) {
            founded = true;
             std::vector<int> letter_map;

        for (long unsigned int i = 0;i < letters.size();i++) {
            letter_map[i] = digits[i];
        }
                   permut=letter_map;
                   std::cout << "Found:!! ";
                   for (int d : permut) std::cout << d << " ";
                   std::cout << std::endl;
                   break; // ou break tous les niveaux si tu veux continuer
        }
        
    } while (std::next_permutation(digits.begin(), digits.end()));*/
    
   // end=genpermut(0, std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, permut, letters, left, right, end);
   for (int a = 0; a < 10; a++) {
       if (a == 0 && must_be_not_null[0] == 1) continue;
  
       if (founded) break;
       for (int b = 0; b < 10; b++) {
           if (founded) break;
           if (b == a || n < 2|| (b == 0 && must_be_not_null[1] == 1)) continue;
           if (n==2) {

               std::vector<int> perm = { a, b };

               if (checkvalide2(perm, letters, left, right)) {
                   founded = true;
                   permut=perm;
                   std::cout << "Found:!! ";
                   for (int d : perm) std::cout << d << " ";
                   std::cout << std::endl;
                   break; // ou break tous les niveaux si tu veux continuer
               }
           }
           for (int c = 0; c < 10; c++) {
               if (founded) break;
               if (c == a || c == b || n < 3 || (c == 0 && must_be_not_null[2] == 1)) continue;
               if (n == (3)) {

                   std::vector<int> perm = { a, b, c };

                   if (checkvalide2(perm, letters, left, right)) {
                       founded = true;
                       permut=perm;
                       std::cout << "Found:!!3 ";
                       for (int d : perm) std::cout << d << " ";
                       std::cout << std::endl;
                       break; // ou break tous les niveaux si tu veux continuer
                   }
               }
               for (int d = 0; d < 10; d++) {
                   if (founded) break;
                   if (d == a || d == b || d == c || n < 4 || (d == 0 && must_be_not_null[3] == 1)) continue;
                   if (n == (4)) {

                       std::vector<int> perm = { a, b, c, d };

                       if (checkvalide2(perm, letters, left, right)) {
                           founded = true;
                               permut=perm;
                           std::cout << "Found:!! ";
                           for (int d : perm) std::cout << d << " ";
                           std::cout << std::endl;
                           break; // ou break tous les niveaux si tu veux continuer
                       }
                   }
                   for (int e = 0; e < 10; e++) {
                       if (founded) break;
                       if (e == a || e == b || e == c || e == d || n < 5 || (e == 0 && must_be_not_null[4] == 1)) continue;
                       if (n == (5)) {

                           std::vector<int> perm = { a, b, c, d, e};

                           if (checkvalide2(perm, letters, left, right)) {
                               founded = true;
                               permut=perm;
                               std::cout << "Found:!! ";
                               for (int d : perm) std::cout << d << " ";
                               std::cout << std::endl;
                               break; // ou break tous les niveaux si tu veux continuer
                           }
                       }
                       for (int f = 0; f < 10; f++) {
                           if (founded) break;
                           if (f == a || f == b || f == c || f == d || f == e || n < 6 || (f == 0 && must_be_not_null[5] == 1)) continue;
                           if (n == (6)) {

                               std::vector<int> perm = { a, b, c, d, e, f};

                               if (checkvalide2(perm, letters, left, right)) {
                                   founded = true;
                               permut=perm;
                                   std::cout << "Found:!! ";
                                   for (int d : perm) std::cout << d << " ";
                                   std::cout << std::endl;
                                   break; // ou break tous les niveaux si tu veux continuer
                               }
                           }
                           for (int g = 0; g < 10; g++) {
                               if (founded) break;
                               if (g == a || g == b || g == c || g == d || g == e || g == f || n < 7 || (g == 0 && must_be_not_null[6] == 1)) continue;
                               if (n == (7)) {

                                   std::vector<int> perm = { a, b, c, d, e, f, g };

                                   if (checkvalide2(perm, letters, left, right)) {
                                       founded = true;
                               permut=perm;
                                       std::cout << "Found:!! ";
                                       for (int d : perm) std::cout << d << " ";
                                       std::cout << std::endl;
                                       break; // ou break tous les niveaux si tu veux continuer
                                   }
                               }
                               for (int h = 0; h < 10; h++) {
                                   if (founded) break;
                                   if (h == a || h == b || h == c || h == d || h == e || h == f || h == g || n < 8 || (h == 0 && must_be_not_null[7] == 1)) continue;
                                   if (n == (8)) {

                                       std::vector<int> perm = { a, b, c, d, e, f, g, h };

                                       if (checkvalide2(perm, letters, left, right)) {
                                           founded = true;
                               permut=perm;
                                           std::cout << "Found:!! ";
                                           for (int d : perm) std::cout << d << " ";
                                           std::cout << std::endl;
                                           break; // ou break tous les niveaux si tu veux continuer
                                       }
                                   }
                                   for (int i = 0; i < 10; i++) {
                                       if (founded) break;
                                       if (i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h || n < 9 || (i == 0 && must_be_not_null[8] == 1)) continue;
                                       if (n == (9)) {

                                           std::vector<int> perm = { a, b, c, d, e, f, g, h, i };

                                           if (checkvalide2(perm, letters, left, right)) {
                                               founded = true;
                               permut=perm;
                                               std::cout << "Found:!! ";
                                               for (int d : perm) std::cout << d << " ";
                                               std::cout << std::endl;
                                               break; // ou break tous les niveaux si tu veux continuer
                                           }
                                       }
                                       for (int j = 0; j < 10; j++) {
                                           if (founded) break;
                                           if (j == a || j == b || j == c || j == d || j == e || j == f || j == g || j == h || j == i || n < 10 || (j == 0 && must_be_not_null[9] == 1)) continue;
                                           if (n == (10)) {

                                               std::vector<int> perm = { a, b, c, d, e, f, g, h, i, j };

                                               if (checkvalide2(perm, letters, left, right)) {
                                                   founded = true;
                               permut=perm;
                                                   std::cout << "Found:!! ";
                                                   for (int d : perm) std::cout << d << " ";
                                                   std::cout << std::endl;
                                                   break; // ou break tous les niveaux si tu veux continuer
                                               }
                                           }
                                       }
                                   }
                               }
                           }
                       }
                   }
               }
           }
       }
   }


    
   /* while (!end) {
        
        // boucle for-each (range-based for loop)
        for (int val : permut) {
            std::cout << val << ' ';
        }
        //std::cout << std::endl;
        end = true;
        for (int i = n - 1;i >= 0;i--) {
            if (permut[i] == 9) {
                permut[i] = 0;
                continue;
            }
            else {
                permut[i]++;
                end = false;
                if (allUnique(permut) && checkvalide(permut, letters, left,right)) {

                    end = true;
                    std::map<char, int> letter_map;

                    for (long unsigned int i = 0;i < letters.size();i++) {
                        letter_map[letters[i]] = permut[i];
                    }
                    std::unordered_map<char, int> result;
                    for (const auto& [key, value] : letter_map) {
                        result[key] = value;
                    }
                return result;
                }
                break;
            }
        }
    }*/

    end=founded;
    if (end) {
        std::map<char, int> letter_map;

        for (long unsigned int i = 0;i < letters.size();i++) {
            letter_map[letters[i]] = permut[i];
        }

        std::cout << "founed : ";
        // Affichage
        for (const auto& pair : letter_map) {
            std::cout << pair.first << " => " << pair.second << std::endl;
        }

    }
    else {
        std::cout << "NOT found ";
    }
    
    if(end==true){
        std::map<char, int> letter_map;

                    for (long unsigned int i = 0;i < letters.size();i++) {
                        letter_map[letters[i]] = permut[i];
                    }
                    std::unordered_map<char, int> result;
                    for (const auto& [key, value] : letter_map) {
                        result[key] = value;
                    }
                return result;
    }
     return std::nullopt;  // retourne "null"
}
}  // namespace alphametics
