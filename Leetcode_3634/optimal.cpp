class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < nums.size(); r++) {
            while (l <= r && (long long)nums[r] > (long long)nums[l] * k) {
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return nums.size() - maxLen;
    }
};