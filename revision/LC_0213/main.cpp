class Solution {
    int robRange(vector<int>& nums, int start, int end) {
        int length = end - start + 1;
        if (length <= 0) return 0;
        
        // dp[i][pre + 1]
        // i goes from 0 to length (representing current offset in the range)
        // pre goes from -1 to length - 1, shifted by +1 (so index 0 to length)
        vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));

        // Bottom-up filling: we can compute from length down to 0
        for (int i = length - 1; i >= 0; i--) {
            for (int pre = -1; pre < length; pre++) {
                int take = 0;
                // If we can take the current house (i.e., no adjacent conflict)
                if (pre == -1 || i - pre > 1) {
                    // When we take, the new 'pre' becomes 'i' (current index)
                    take = nums[start + i] + dp[i + 1][i + 1];
                }
                // Skip the current house (keep the old 'pre')
                int skip = dp[i + 1][pre + 1];

                dp[i][pre + 1] = max(take, skip);
            }
        }

        // Return result starting at index 0 with no previous house chosen (pre = -1 -> index 0)
        return dp[0][0];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Case 1: Exclude the last house (indices 0 to n-2)
        int case1 = robRange(nums, 0, n - 2);

        // Case 2: Exclude the first house (indices 1 to n-1)
        int case2 = robRange(nums, 1, n - 1);

        return max(case1, case2);
    }
};