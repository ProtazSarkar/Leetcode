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
    long long getSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        long long ans = LLONG_MIN;

        // -------- Odd palindromes --------
        vector<int> d1(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

            while (i - k >= 0 && i + k < n &&
                   nums[i - k] == nums[i + k])
                k++;

            d1[i] = k--;

            if (i + k > r) {
                l = i - k;
                r = i + k;
            }

            int L = i - d1[i] + 1;
            int R = i + d1[i] - 1;
            ans = max(ans, pref[R + 1] - pref[L]);
        }

        // -------- Even palindromes --------
        vector<int> d2(n);
        l = 0;
        r = -1;

        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

            while (i - k - 1 >= 0 &&
                   i + k < n &&
                   nums[i - k - 1] == nums[i + k])
                k++;

            d2[i] = k--;

            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }

            if (d2[i] > 0) {
                int L = i - d2[i];
                int R = i + d2[i] - 1;
                ans = max(ans, pref[R + 1] - pref[L]);
            }
        }

        return ans;
    }
};
