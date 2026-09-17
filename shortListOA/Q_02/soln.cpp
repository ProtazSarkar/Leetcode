#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> getMinimumCost(vector<int>& cost, vector<string>& featureAvailability) {
        int n = cost.size();
        
        vector<int> onlyA, onlyB, both;
        for (int i = 0; i < n; ++i) {
            if (featureAvailability[i] == "01") {
                onlyA.push_back(cost[i]);
            } else if (featureAvailability[i] == "10") {
                onlyB.push_back(cost[i]);
            } else if (featureAvailability[i] == "11") {
                both.push_back(cost[i]);
            }
        }
        
        // Sort individual cost vectors to greedily pick the cheapest options
        sort(onlyA.begin(), onlyA.end());
        sort(onlyB.begin(), onlyB.end());
        sort(both.begin(), both.end());
        
        int szA = onlyA.size();
        int szB = onlyB.size();
        int szBoth = both.size();
        
        // Compute prefix sums for quick range cost lookups
        vector<long long> prefA(szA + 1, 0), prefB(szB + 1, 0), prefBoth(szBoth + 1, 0);
        for (int i = 0; i < szA; ++i) prefA[i + 1] = prefA[i] + onlyA[i];
        for (int i = 0; i < szB; ++i) prefB[i + 1] = prefB[i] + onlyB[i];
        for (int i = 0; i < szBoth; ++i) prefBoth[i + 1] = prefBoth[i] + both[i];
        
        vector<int> result(n, -1);
        
        // k ranges from 1 to n
        for (int k = 1; k <= n; ++k) {
            long long minCost = -1;
            
            // i models taken from 'both'
            for (int i = 0; i <= szBoth; ++i) {
                // We need max(0, k - i) models from onlyA and onlyB respectively
                int neededA = max(0, k - i);
                int neededB = max(0, k - i);
                
                if (neededA <= szA && neededB <= szB) {
                    long long currentCost = prefBoth[i] + prefA[neededA] + prefB[neededB];
                    if (minCost == -1 || currentCost < minCost) {
                        minCost = currentCost;
                    }
                }
            }
            
            // Check bounds for int limits
            if (minCost != -1 && minCost <= INT_MAX) {
                result[k - 1] = (int)minCost;
            }
        }
        
        return result;
    }
};

// Example Test Case
int main() {
    Solution sol;
    int n = 6;
    vector<int> cost = {3, 6, 9, 1, 2, 5};
    vector<string> featureAvailability = {"10", "01", "11", "01", "11", "10"};
    
    vector<int> ans = sol.getMinimumCost(cost, featureAvailability);
    
    cout << "Result: [";
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i + 1 == ans.size() ? "" : ", ");
    }
    cout << "]" << endl;
    
    return 0;
}