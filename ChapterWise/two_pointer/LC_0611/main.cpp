#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        int count = 0;

        // Step 2: Fix the largest side at index k
        for (int k = n - 1; k >= 2; k--) {
            int left = 0;
            int right = k - 1;

            // Step 3: Use two pointers to find valid pairs
            while (left < right) {
                if (nums[left] + nums[right] > nums[k]) {
                    // All elements from left to right-1 will form valid triangles with right and k
                    count += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }

        return count;
    }
};