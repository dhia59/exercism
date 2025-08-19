#include "largest_series_product.h"

namespace largest_series_product {

// TODO: add your solution here

    int largest_product(const std::string& input, int span) {
        if (input.empty() && span > 0) {
            throw std::domain_error("Empty string with non-zero span");
        }

        if (span < 0) {
            throw std::domain_error("Span must be non-negative");
        }

        if (span > static_cast<int>(input.size())) {
            throw std::domain_error("Span is bigger than string size");
        }

        // Vérifier que tous les caractères sont des chiffres
        for (char c : input) {
            if (!std::isdigit(c)) {
                throw std::domain_error("Input contains non-digit characters");
            }
        }

        int maxproduct=0;
        for(long unsigned int i=0;i<=(input.length()-span);i++){
            int product=1;
            for(int j=0;j<span;j++){
                product*=input[i+j]-48;
            }
            if(product>maxproduct)
                maxproduct=product;
        }
        return maxproduct;
    }
}  // namespace largest_series_product