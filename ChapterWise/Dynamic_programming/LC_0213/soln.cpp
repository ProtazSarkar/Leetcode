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
    int solve(int start, int end, vector<int>& nums, int pre, vector<vector<int>>& memo) {
        if (start > end) {
            return 0;
        }

        // Shift 'pre' by +1 to handle -1 index (-1 becomes 0, 0 becomes 1, etc.)
        if (memo[start][pre + 1] != -1) {
            return memo[start][pre + 1];
        }

        int take = 0;
        if (pre == -1 || start - pre > 1) {
            take = nums[start] + solve(start + 1, end, nums, start, memo);
        }

        int skip = solve(start + 1, end, nums, pre, memo);

        // Store and return the result
        return memo[start][pre + 1] = max(take, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // memo table of size n x (n + 1) initialized with -1
        // rows: start (0 to n-1)
        // cols: pre + 1 (0 to n)
        vector<vector<int>> memo1(n, vector<int>(n + 1, -1));
        int start_from_0 = solve(0, n - 2, nums, -1, memo1);

        vector<vector<int>> memo2(n, vector<int>(n + 1, -1));
        int start_from_1 = solve(1, n - 1, nums, -1, memo2);

        return max(start_from_0, start_from_1);
    }
};