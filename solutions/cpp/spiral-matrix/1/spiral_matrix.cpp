#include "spiral_matrix.h"

namespace spiral_matrix {

// TODO: add your solution here
std::vector<std::vector<uint32_t>> spiral_matrix(int n) {
    std::vector<std::vector<uint32_t>> matrix(n, std::vector<uint32_t>(n, 0));
    int maxL = n - 1;
    int maxC = n - 1;
    int minL = 0;
    int minC = 0;
    int currentL = 0;
    int currentC = 0;
    int direction = 0; //0 => column up 1 > row up 2 => column down 3 => row down

    for (int i = 1;i <= (n * n);i++) {
        matrix[currentL][currentC] = i;
        if (direction == 0) {
            currentC++;
        }
        else if (direction == 1) {
            currentL++;
        }
        else if (direction == 2) {
            currentC--;
        }
        else if (direction == 3) {
            currentL--;
        }


        if (currentC > maxC) {
            if (currentL == minL) {
                direction = 1;
                currentL++;
            }
            currentC = maxC;
            minL++;
        }
        if (currentL > maxL) {
            if (currentC == maxC) {
                direction = 2;
                currentC--;
            }
            currentL = maxL;
            maxC--;
        }
        if (currentC < minC) {
            if (currentL == maxL) {
                direction = 3;
                currentL--;
            }
            currentC = minC;
            maxL--;
        }
        if (currentL < minL) {
            if (currentC == minC) {
                direction = 0;
                currentC++;
            }
            currentL = minL;
            minC++;
        }
    }


    return matrix;
}

    
}  // namespace spiral_matrix
