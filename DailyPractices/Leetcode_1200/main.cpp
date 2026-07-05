#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // 1. Sort the array so that the closest numbers are neighbors
        sort(arr.begin(), arr.end());
        
        int min_diff = INT_MAX;
        vector<vector<int>> ans;
        
        // 2. Single pass to find the minimum difference and collect pairs
        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = arr[i+1] - arr[i];
            
            if (diff < min_diff) {
                // Found a new smaller difference: clear previous pairs
                min_diff = diff;
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
            } else if (diff == min_diff) {
                // Found another pair with the same minimum difference
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};

int main() {
    // Blank main for local compilation
    return 0;
}
