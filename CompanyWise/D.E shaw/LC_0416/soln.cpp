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
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(int num : nums){
            total_sum += num;
        }

        // If the total sum is odd, we can't split it into two equal integer subsets
        if(total_sum % 2 != 0) return false;

        int req_sum = total_sum / 2;
        
        // Fix 1: Corrected type to vector<bool>
        vector<vector<bool>> dp(n + 1, vector<bool>(req_sum + 1, false));

        // Fix 2: Base case - a sum of 0 is always possible (by picking no elements)
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fix 3: Proper loop bounds and state transitions
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= req_sum; j++) {
                // Scenario A: Exclude the current element nums[i-1]
                dp[i][j] = dp[i-1][j];
                
                // Scenario B: Include the current element (if it fits)
                if(j >= nums[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
                }
            }
        }

        return dp[n][req_sum];
    }
};