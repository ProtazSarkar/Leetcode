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
    int memo[25][25]; // Assuming max constraints for nums.length are small (e.g., <= 20)
    
    int solve(int start, int end, vector<int>& nums) {
        if (start > end) {
            return 0;
        }
        if (memo[start][end] != -1) {
            return memo[start][end];
        }

        // Current player chooses either the first or the last element
        // They get the current element minus whatever the optimal score 
        // difference was for the opponent on the remaining subarray.
        int pickFirst = nums[start] - solve(start + 1, end, nums);
        int pickLast  = nums[end] - solve(start, end - 1, nums);

        return memo[start][end] = max(pickFirst, pickLast);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        // If the max score difference for player 1 is >= 0, they win or tie.
        return solve(0, nums.size() - 1, nums) >= 0;
    }
};