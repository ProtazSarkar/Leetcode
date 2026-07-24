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
    bool canMakeSubsequence(string s, string t) {
        int m = s.size(), n = t.size();

        vector<int> pref(m), suff(m);

        // Prefix matching
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j < n && t[j] != s[i])
                j++;

            if (j == n)
                pref[i] = n;
            else
                pref[i] = j++;
        }

        if (pref[m - 1] != n)
            return true;

        // Suffix matching
        j = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i])
                j--;

            if (j < 0)
                suff[i] = -1;
            else
                suff[i] = j--;
        }

        for (int i = 0; i < m; i++) {
            int left = (i == 0) ? -1 : pref[i - 1];
            int right = (i == m - 1) ? n : suff[i + 1];

            if (left < right)
                return true;
        }

        return false;
    }
};