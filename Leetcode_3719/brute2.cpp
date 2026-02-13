class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        
        // Count total unique elements to define our search space
        unordered_set<int> totalUnique(nums.begin(), nums.end());
        int maxUnique = totalUnique.size();

        for (int k = 1; k <= maxUnique; k++) {
            unordered_map<int, int> windowCounts;
            int distinctEven = 0, distinctOdd = 0, currentUnique = 0;
            int left = 0;

            for (int right = 0; right < n; right++) {
                // Add right element
                if (windowCounts[nums[right]] == 0) {
                    currentUnique++;
                    if (nums[right] % 2 == 0) distinctEven++;
                    else distinctOdd++;
                }
                windowCounts[nums[right]]++;

                // Shrink left if we exceed k unique elements
                while (currentUnique > k) {
                    windowCounts[nums[left]]--;
                    if (windowCounts[nums[left]] == 0) {
                        currentUnique--;
                        if (nums[left] % 2 == 0) distinctEven--;
                        else distinctOdd--;
                    }
                    left++;
                }

                // Check if the window is balanced
                if (distinctEven == distinctOdd) {
                    maxLen = max(maxLen, right - left + 1);
                }
            }
        }
        return maxLen;
    }
};
