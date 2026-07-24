#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        const int INF = 1e9;

        int first_min_idx = -1;
        int minimum = INF;

        // find first minimum index (excluding nums[0])
        for (int i = 1; i < n; i++) {
            if (nums[i] < minimum) {
                minimum = nums[i];
                first_min_idx = i;
            }
        }

        // find second minimum index (excluding nums[0] and first_min_idx)
        int sec_min_idx = -1;
        minimum = INF;

        for (int i = 1; i < n; i++) {
            if (i != first_min_idx && nums[i] < minimum) {
                minimum = nums[i];
                sec_min_idx = i;
            }
        }

        return nums[0] + nums[first_min_idx] + nums[sec_min_idx];
    }
};