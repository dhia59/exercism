#include "knapsack.h"

namespace knapsack {

// TODO: add your solution here



int SumVal(const std::vector<Item>& items, int max_weight) {
    int sum = 0;
    int current_weight = 0;
    for (const auto& item : items) {
        current_weight += item.weight;
        if (current_weight > max_weight) {
            return 0; // Exceeds max weight, return 0
        }
        sum += item.value;
    }
    return sum;
}
void check_comb_rec(int& maxval,int max_weight,const std::vector<Item>& items, long unsigned int size,
    std::vector<Item> comp = {}, int start = 0) {
    if (comp.size() == size) {
     
		int m=SumVal(comp, max_weight); // Assuming max_weight is 10 for this example
		if (m > maxval) {
			maxval = m;
		}
        return;
    }

    for (long unsigned int i = start; i < items.size(); ++i) {
        comp.push_back(items[i]);
        check_comb_rec(maxval,max_weight,items, size, comp, i + 1);
        comp.pop_back();
    }
}

int maximum_value(int max_weight, const std::vector<Item>& items) {

	int max_value = 0;
    for (long unsigned int i = 1;i <= items.size(); ++i) {
        check_comb_rec(max_value, max_weight,items, i, std::vector<Item>());

    }
    return max_value;
    }
}  // namespace knapsack
