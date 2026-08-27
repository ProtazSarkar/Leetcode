#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    bool is_possible(int target_sum, const vector<int>& load, int k) {
        int servers_needed = 1;
        int curr_sum = 0;

        for (int x : load) {
            if (curr_sum + x > target_sum) {
                servers_needed++;
                curr_sum = x;
            } else {
                curr_sum += x;
            }
        }
        return servers_needed <= k;
    }

public:
    int splitArray(vector<int>& load, int k) {
        int left = 0;
        int right = 0;

        for (int x : load) {
            left = max(left, x); // Max single element
            right += x;          // Total sum of array
        }

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (is_possible(mid, load, k)) {
                ans = mid;
                right = mid - 1; // Try smaller maximum sum
            } else {
                left = mid + 1;  // Need a larger allowed sum
            }
        }
        return ans;
    }
};