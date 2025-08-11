#include "difference_of_squares.h"

namespace difference_of_squares {

    double square_of_sum(int n) {
        double res = 0;
        std::vector<int> naturales = getFirstNNaturalNumbers(n);
        for (int p : naturales) {
            res += p;
        }
        return res * res;
    }
    double sum_of_squares(int n) {
        double res = 0;
        std::vector<int> naturales = getFirstNNaturalNumbers(n);
        for (int p : naturales) {
            res += p * p;
        }
        return res;
    }
    double difference(int n) {
        return     square_of_sum(n) - sum_of_squares(n);
    }



    // Function to return the first n prime numbers
    std::vector<int> getFirstNNaturalNumbers(int n) {
        std::vector<int> numbers;
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }
        return numbers;
    }
    
}  // namespace difference_of_squares
