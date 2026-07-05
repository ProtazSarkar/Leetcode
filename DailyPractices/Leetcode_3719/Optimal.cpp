class Solution {
public:
    // Static array to track seen numbers across different calls
    inline static uint32_t seen[100001] = {};
    inline static uint32_t session = 0;

    int longestBalanced(vector<int>& nums) {
        // Increment session to 'reset' our seen array in O(1)
        session++;
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            // Pruning: if remaining elements can't beat maxLen, break
            if (n - i <= maxLen) break;

            int counts[2] = {0, 0}; // counts[0]: even, counts[1]: odd
            
            // Unique marker for this specific starting index i
            uint32_t marker = (session << 16) | (uint32_t)(i + 1);

            for (int j = i; j < n; j++) {
                int val = nums[j];

                // If this is a distinct number for the current subarray
                if (seen[val] != marker) {
                    seen[val] = marker;
                    counts[val & 1]++;
                }

                // Check if distinct even count == distinct odd count
                if (counts[0] == counts[1]) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
