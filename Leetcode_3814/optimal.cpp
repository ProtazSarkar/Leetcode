#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        int maxCap = 0;

        // Step 1: single items
        for (int i = 0; i < n; i++) {
            if (costs[i] < budget) 
                maxCap = max(maxCap, capacity[i]);
        }

        // Step 2: map cost -> vector of indices
        map<int, vector<int>> costMap;
        for (int i = 0; i < n; i++)
            costMap[costs[i]].push_back(i);

        // Step 3: for each item, find valid second items
        for (int i = 0; i < n; i++) {
            int remBudget = budget - costs[i];
            if (remBudget <= 0) continue;

            // upper_bound returns first key > remBudget → we want strictly less
            auto it = costMap.lower_bound(remBudget);

            // iterate all keys less than remBudget
            for (auto rit = make_reverse_iterator(it); rit != costMap.rend(); ++rit) {
                int costKey = rit->first;
                const vector<int>& indices = rit->second;

                for (int j : indices) {
                    if (i == j) continue; // cannot pick same item
                    int totalCap = capacity[i] + capacity[j];
                    maxCap = max(maxCap, totalCap);
                }
            }
        }

        return maxCap;
    }
};