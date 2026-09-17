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
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n == 0 || n < k) return 0;
        if (k <= 1) return n;

        // Count frequencies of each character
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Find the first character that violates the condition (< k)
        int idx = 0;
        while (idx < n && count[s[idx] - 'a'] >= k) {
            idx++;
        }

        // If all characters are valid, the whole string is valid
        if (idx == n) return n;

        // Otherwise, split the string at the invalid character and recurse
        int left = longestSubstring(s.substr(0, idx), k);
        
        // Skip all consecutive instances of the invalid character
        while (idx < n && count[s[idx] - 'a'] < k) {
            idx++;
        }
        
        int right = longestSubstring(s.substr(idx), k);

        return max(left, right);
    }
};