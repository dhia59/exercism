#include "word_count.h"

namespace word_count {

// TODO: add your solution here
    // Déclaration
   
std::map<std::string, int> words(std::string subtitle) {
    std::map<std::string, int> wordsCounts;
    std::string word = "";
    bool isSeparator = true;
    for (long unsigned int i = 0;i < subtitle.length();i++) {

        if ((subtitle[i] >= 48 && subtitle[i] <= 57) ||   // chiffres 0-9
            (subtitle[i] >= 65 && subtitle[i] <= 90) ||   // lettres majuscules A-Z
            (subtitle[i] >= 97 && subtitle[i] <= 122) ||  // lettres minuscules a-z
            subtitle[i] == '\'')                         // apostrophe '
        {
            if (subtitle[i] == '\'' && word == "") continue;
            word += std::tolower(subtitle[i]);
            isSeparator = false; // on est en train de construire un mot
        }

        if (isSeparator or i == subtitle.length() - 1) {
            if (word.length() == 0 || word == "'") continue;
            if (subtitle[i - 1] == '\'') word.erase(word.size() - 1);
            if (subtitle[i] == '\'') word.erase(word.size() - 1);
            auto it = wordsCounts.find(word);
            if (it != wordsCounts.end()) {
                std::cout << word << " existe déjà avec valeur " << it->second << "\n";
                wordsCounts[word] += 1;
            }
            else {
                wordsCounts[word] = 1; // crée la clé avec valeur 0
                std::cout << word << " ajouté avec valeur 0\n";
            }

            word = "";
        }
        isSeparator = true;

    }

    return wordsCounts;



}   
}  // namespace word_count
