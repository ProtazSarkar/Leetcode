#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getNum(int p) {
        for (int i = 0; i < p; i++) {
            if ((i | (i + 1)) == p) {
                return i;   // minimum i found
            }
        }
        return -1;  // not possible
    }

public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = getNum(nums[i]);
        }
        return ans;
    }
};
