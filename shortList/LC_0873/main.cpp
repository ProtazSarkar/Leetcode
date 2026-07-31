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
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        unordered_map<int, int> numToIndex;
        for (int i = 0; i < n; i++) {
            numToIndex[arr[i]] = i;
        }

        // dp[i][j] stores the length of the Fibonacci-like subsequence ending at indices i and j
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxLen = 0;

        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int target = arr[k] - arr[j];
                
                // Check if 'target' exists and appears before arr[j] (index i < j)
                if (target < arr[j] && numToIndex.count(target)) {
                    int i = numToIndex[target];
                    dp[j][k] = dp[i][j] + 1;
                    maxLen = max(maxLen, dp[j][k]);
                }
            }
        }

        return maxLen >= 3 ? maxLen : 0;
    }
};