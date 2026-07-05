#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i, j;
        
        // Step 1: Find the first element from the right that breaks descending order
        // The loop continues AS LONG AS nums[i] >= nums[i+1]
        for (i = n - 2; i >= 0 && nums[i] >= nums[i + 1]; i--) {
            // Empty body; all action happens in the loop header
        }
        
        // Step 2: If a valid pivot is found, find its successor and swap
        if (i >= 0) {
            // The loop continues AS LONG AS nums[j] <= nums[i]
            for (j = n - 1; nums[j] <= nums[i]; j--) {
                // Empty body
            }
            swap(nums[i], nums[j]);
        }
        
        // Step 3: Reverse the suffix elements manually using a for loop
        // We use two pointers (left and right) moving toward each other
        for (int left = i + 1, right = n - 1; left < right; left++, right--) {
            swap(nums[left], nums[right]);
        }
    }
};