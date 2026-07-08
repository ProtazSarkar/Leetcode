#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if we can split the array into <= k subarrays
    // such that no subarray sum exceeds 'max_sum_limit'.
    bool is_possible(const vector<int>& nums, int k, int max_sum_limit) {
        int subarray_count = 1;
        int current_sum = 0;

        for (int num : nums) {
            // If a single element is greater than the limit, it's impossible
            if (num > max_sum_limit) return false;

            if (current_sum + num > max_sum_limit) {
                // Start a new subarray
                subarray_count++;
                current_sum = num;
                
                // If we need more than k subarrays, this limit is too small
                if (subarray_count > k) {
                    return false;
                }
            } else {
                current_sum += num;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int max_element = 0;
        int total_sum = 0;

        for (int num : nums) {
            max_element = max(max_element, num);
            total_sum += num;
        }

        // Binary search range
        int l = max_element;
        int h = total_sum;
        int ans = h;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (is_possible(nums, k, mid)) {
                ans = mid;        // 'mid' is a valid maximum sum, try to find a smaller one
                h = mid - 1;
            } else {
                l = mid + 1;      // 'mid' is too small, look for a larger capacity
            }
        }

        return ans;
    }
};