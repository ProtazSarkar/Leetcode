#include <iostream>
#include <sstream>

// Containers
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[i] stores the maximum sum found so far that has a remainder of 'i' when divided by 3
        // We start with 0 for remainder 0. INT_MIN means the remainder is currently impossible.
        vector<int> dp = {0, INT_MIN, INT_MIN};
        
        for (int num : nums) {
            vector<int> next_dp = dp; // Copy current state to safely transition
            
            for (int i = 0; i < 3; ++i) {
                if (dp[i] != INT_MIN) { // If this remainder state is reachable
                    int new_sum = dp[i] + num;
                    int remainder = new_sum % 3;
                    
                    // Keep the absolute maximum sum for this specific remainder
                    next_dp[remainder] = max(next_dp[remainder], new_sum);
                }
            }
            dp = next_dp; // Move to the next element
        }
        
        // Return the maximum sum that has a remainder of 0
        return dp[0];
    }
};