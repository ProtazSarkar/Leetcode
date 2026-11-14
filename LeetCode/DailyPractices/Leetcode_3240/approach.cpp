#include <iostream>
#include <sstream>

// Containers
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>

// Associative Containers (Trees/Hashes)
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

// Algorithms & Utilities
#include <algorithm>
#include <numeric>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k_budget) {
        int n = nums.size();
        long long ans = 0;

        vector<long long> prefix_sum(n + 1, 0);
        vector<int> next_greater_element(n, n);
        stack<int> s;

        // 1. Precompute next greater element using monotonic stack
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                next_greater_element[i] = s.top();
            }
            s.push(i);
        }

        // 2. Precompute prefix sums
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        int left = 0, pre = 0;
        long long cost = 0;

        // 3. Sliding window
        for (int right = 0; right < n; right++) {
            if (nums[pre] > nums[right]) {
                int inc = nums[pre] - nums[right];
                cost += inc;
            } else {
                pre = right;
            }

            // Fixed: Added `left <= right` to prevent infinite loops
            while (cost > k_budget && left <= right) {
                left++;
                int curr = left;cost = 0;
                while (curr < right) {
                    int next = min(next_greater_element[curr], right);
                    long long w = next - curr + 1;
                    cost += (long long)nums[curr] * w - (prefix_sum[next + 1] - prefix_sum[curr]);
                    pre = (nums[curr] > nums[next]) ? curr : next;
                    curr = next;  
                }
                 // Safely shrink window from the left
            }

            ans += (right - left + 1);
        }

        return ans;
    }
};