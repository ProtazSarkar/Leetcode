class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // If we encounter a negative number, max and min products swap
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }

            // Update max and min product considering the current element
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            // Update the global maximum result
            result = max(result, maxProd);
        }

        return result;
    }
};