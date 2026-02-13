class Solution {
    // Helper function to check if a subarray is balanced
    bool is_balanced(vector<int>& arr, int l, int h) {
        int evenCount = 0;
        int oddCount = 0;
        unordered_map<int, int> map;

        for (int i = l; i <= h; i++) {
            // Check if we have already counted this distinct number
            auto it = map.find(arr[i]);
            if (it != map.end()) {
                continue;
            }
            
            // Mark number as seen
            map.insert({arr[i], i});

            // Increment based on parity
            if (arr[i] & 1) {
                oddCount++;
            } else {
                evenCount++;
            }
        }
        return evenCount == oddCount;
    }

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        // Iterate through all possible subarray start points
        for (int i = 0; i < n; i++) {
            // Iterate through all possible subarray end points
            for (int j = i + 1; j < n; j++) {
                if (is_balanced(nums, i, j)) {
                    maxLen = max(maxLen, (j - i + 1));
                }
            }
        }
        return maxLen;
    }
};
