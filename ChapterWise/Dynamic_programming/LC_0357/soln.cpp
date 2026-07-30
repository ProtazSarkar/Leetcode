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
    int memo[11][1024];

    int dfs(int i, int mask, bool lead, int n) {
        if (i == n) return 1; // Successfully formed a valid number
        
        // Use memoization state (ignoring lead state for simplicity or tracking it)
        if (!lead && memo[i][mask] != -1) return memo[i][mask];

        int ans = 0;
        for (int j = 0; j <= 9; ++j) {
            if ((mask >> j) & 1) continue; // Digit already used

            if (lead && j == 0) {
                // Allow leading zeros (they don't trigger uniqueness constraints yet)
                ans += dfs(i + 1, mask, true, n);
            } else {
                ans += dfs(i + 1, mask | (1 << j), false, n);
            }
        }

        if (!lead) memo[i][mask] = ans;
        return ans;
    }

public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, true, n);
    }
};