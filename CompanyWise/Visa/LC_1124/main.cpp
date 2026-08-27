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
    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        // prefix[i] = sum of first i days
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (hours[i] > 8)
                prefix[i + 1] = prefix[i] + 1;
            else
                prefix[i + 1] = prefix[i] - 1;
        }

        // Store indices where prefix reaches a new minimum
        stack<int> s;

        for (int i = 0; i <= n; i++) {
            if (s.empty() || prefix[i] < prefix[s.top()]) {
                s.push(i);
            }
        }

        int ans = 0;

        // Start from n, NOT n-1
        for (int i = n; i >= 0; i--) {

            while (!s.empty() &&
                   prefix[i] > prefix[s.top()]) {

                ans = max(ans, i - s.top());

                s.pop();
            }
        }

        return ans;
    }
};