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

//this one failed
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        int j = 0;
        int lastMatched = 0;

        // First subsequence check
        for (int i = 0; i < n && j < m; i++) {
            if (s[j] == t[i]) {
                lastMatched = i;
                j++;
            }
        }

        if (j == m)
            return true;

        int changeIndex = j;
        int nextDifferent = lastMatched;

        // Find the next different character in t
        while (nextDifferent < n && t[nextDifferent] == t[lastMatched]) {
            nextDifferent++;
        }

        if (nextDifferent == n)
            return false;

        // Replace the current character in s
        s[changeIndex] = t[nextDifferent];

        // Check again
        j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (s[j] == t[i]) {
                j++;
            }
        }

        return (j == m);
    }
}; 