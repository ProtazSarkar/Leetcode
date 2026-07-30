#include <iostream>
#include <sstream>

// Containers
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>

// Associative Containers (Trees/Hashes)
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

// Algorithms & Utilities
#include <algorithm>
#include <numeric>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxPro = 0;

        for (int i = 0; i < prices.size(); i++) {
            // Update the minimum price encountered so far
            minPrice = min(minPrice, prices[i]);
            
            // Calculate the profit if we sell at the current price
            int currentProfit = prices[i] - minPrice;
            
            // Update the maximum profit if the current one is higher
            maxPro = max(maxPro, currentProfit);
        }

        return maxPro;
    }
};