#include <vector>
#include <algorithm>

class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // dp[i][j] will store the length of common subarray ending at nums1[i-1] and nums2[j-1]
        std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
        int ans = 0;

        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};