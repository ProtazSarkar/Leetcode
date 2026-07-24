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
    string smallestSubsequence(string s) {
        string ans = "";
        vector<int> count(256, 0);
        vector<bool> seen(256, false);

        // Pre-calculate frequencies
        for (char c : s) {
            count[c]++;
        }

        for (char c : s) {
            // We have processed one more instance of this character
            count[c]--;

            if (seen[c]) continue;

            // Maintain monotonic property:
            // Pop if top of stack > current char AND 
            // the top character will appear again later
            while (!ans.empty() && ans.back() > c && count[ans.back()] > 0) {
                seen[ans.back()] = false; 
                ans.pop_back();
            }

            ans.push_back(c);
            seen[c] = true;
        }

        return ans;
    }
};