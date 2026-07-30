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
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        // dp[i][0] -> max alternating sum starting at index i, where we ADD nums[i]
        // dp[i][1] -> max alternating sum starting at index i, where we SUBTRACT nums[i]
        // Size: (n + 1) x 2
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        // Base case: when i == n, the sum is 0 (handled automatically by zero-initialization)

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 2; ++j) {
                long long take = 0;
                if (j == 0) {
                    // We need to add nums[i], next element will be subtracted (j = 1)
                    take = nums[i] + dp[i + 1][1];
                } else {
                    // We need to subtract nums[i], next element will be added (j = 0)
                    take = -nums[i] + dp[i + 1][0];
                }

                long long skip = dp[i + 1][j]; // Skip the current element

                dp[i][j] = max(take, skip);
            }
        }

        // We start at index 0 with j = 0 (first element must be added)
        return dp[0][0];
    }
};