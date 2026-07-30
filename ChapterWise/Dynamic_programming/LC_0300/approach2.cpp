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
    int memo[2505][2505]; // Adjust size based on constraints (e.g., nums.length <= 2500)

    int solve(int i, int prev_index, vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }

        // prev_index + 1 because prev_index starts at -1
        if (memo[i][prev_index + 1] != -1) {
            return memo[i][prev_index + 1];
        }

        // Option 1: Skip current element
        int skip = solve(i + 1, prev_index, nums);

        // Option 2: Take current element (if it's greater than the previous taken element)
        int take = 0;
        if (prev_index == -1 || nums[i] > nums[prev_index]) {
            take = 1 + solve(i + 1, i, nums);
        }

        return memo[i][prev_index + 1] = max(skip, take);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return solve(0, -1, nums);
    }
};