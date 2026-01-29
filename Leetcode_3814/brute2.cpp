#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int solve(int i, int remainBudget, int itemsLeft, vector<int>& cost, vector<int>& capacity) {
        if (i >= cost.size() || itemsLeft == 0) return 0;

        // Case 1: skip current item
        int skip = solve(i + 1, remainBudget, itemsLeft, cost, capacity);

        // Case 2: take current item (if budget allows)
        int take = 0;
        if (remainBudget > cost[i]) {
            take = capacity[i] + solve(i + 1, remainBudget - cost[i], itemsLeft - 1, cost, capacity);
        }

        return max(skip, take);
    }

public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        return solve(0, budget, 2, costs, capacity);
    }
};