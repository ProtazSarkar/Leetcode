#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Double the array to simulate circular behavior
        vector<int> arr(2 * n);
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
            arr[i + n] = nums[i];
        }

        // 2. Compute prefix sums of the doubled array
        vector<long long> pref(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            pref[i + 1] = pref[i] + arr[i];
        }

        long long max_sum = nums[0];
        deque<int> dq; // Stores indices of prefix sums

        // 3. Sliding window using monotonic queue to find max subarray of length <= n
        for (int j = 0; j < 2 * n; j++) {
            // Remove indices that fall outside the window of size n
            while (!dq.empty() && dq.front() < j - n + 1) {
                dq.pop_front();
            }

            // The best subarray ending at 'j' starts at dq.front()
            if (!dq.empty()) {
                max_sum = max(max_sum, pref[j + 1] - pref[dq.front()]);
            }

            // Maintain a monotonically increasing deque of prefix sums
            while (!dq.empty() && pref[dq.back()] >= pref[j + 1]) {
                dq.pop_back();
            }
            dq.push_back(j + 1);
        }

        return max_sum;
    }
};