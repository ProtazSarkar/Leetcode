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
    int memo[1005][1005];

    int solve(int i, int j, const string& s) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == s[j]) {
            return memo[i][j] = 2 + solve(i + 1, j - 1, s);
        } else {
            return memo[i][j] = max(solve(i + 1, j, s), solve(i, j - 1, s));
        }
    }

public:
    int longestPalindromeSubseq(string s) {
        memset(memo, -1, sizeof(memo));
        return solve(0, s.length() - 1, s);
    }
};