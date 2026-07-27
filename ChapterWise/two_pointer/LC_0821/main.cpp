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
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n);
        
        // --- Pass 1: Left to Right ---
        int prev = -n; // Initialize with a very small/negative index
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                prev = i;
            }
            ans[i] = i - prev;
        }
        
        // --- Pass 2: Right to Left ---
        prev = 2 * n; // Initialize with a very large index
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                prev = i;
            }
            ans[i] = min(ans[i], prev - i);
        }
        
        return ans;
    }
};