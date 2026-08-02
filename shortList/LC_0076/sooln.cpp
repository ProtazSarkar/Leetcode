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
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        vector<int> t_freq(128, 0);
        for (char c : t) {
            t_freq[c]++;
        }

        int required = 0; // Number of unique characters that need to match their frequency
        for (int i = 0; i < 128; i++) {
            if (t_freq[i] > 0) required++;
        }

        int l = 0, r = 0;
        int formed = 0; // Unique characters currently matching their required frequency
        vector<int> window_freq(128, 0);

        // Indices to store the minimum window found: {length, left_start}
        int min_len = 1e9, window_start = 0;

        while (r < s.length()) {
            char c = s[r];
            window_freq[c]++;

            // If the current character's frequency matches the target frequency, increment 'formed'
            if (t_freq[c] > 0 && window_freq[c] == t_freq[c]) {
                formed++;
            }

            // Try and contract the window until it ceases to be 'valid'
            while (l <= r && formed == required) {
                c = s[l];

                // Update the minimum window if a smaller one is found
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    window_start = l;
                }

                // Character at the left pointer is about to be excluded
                window_freq[c]--;
                if (t_freq[c] > 0 && window_freq[c] < t_freq[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }

        return min_len == 1e9 ? "" : s.substr(window_start, min_len);
    }
};