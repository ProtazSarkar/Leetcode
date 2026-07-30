#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int memo[1005][1005]; // memo[curr][prev+1] to handle -1 offset

    // Returns the maximum length of a divisible subset starting at curr_index 
    // given that the last chosen element was at prev_index.
    int getMaxLength(vector<int>& nums, int curr, int prev) {
        if (curr == nums.size()) {
            return 0;
        }

        // prev + 1 because prev starts at -1
        if (memo[curr][prev + 1] != -1) {
            return memo[curr][prev + 1];
        }

        // Choice 1: Skip the current element
        int skip = getMaxLength(nums, curr + 1, prev);
        
        // Choice 2: Take the current element (if valid)
        int take = 0;
        if (prev == -1 || nums[curr] % nums[prev] == 0) {
            take = 1 + getMaxLength(nums, curr + 1, curr);
        }

        return memo[curr][prev + 1] = max(skip, take);
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        memset(memo, -1, sizeof(memo));

        // Reconstruct the subset by following the same optimal choices
        vector<int> result;
        int curr = 0;
        int prev = -1;

        while (curr < n) {
            int take_len = 0;
            // Check if we can take the current element
            if (prev == -1 || nums[curr] % nums[prev] == 0) {
                take_len = 1 + getMaxLength(nums, curr + 1, curr);
            }
            int skip_len = getMaxLength(nums, curr + 1, prev);

            // If taking gives the optimal remaining length, we take it
            if (take_len >= skip_len && take_len > 0) {
                result.push_back(nums[curr]);
                prev = curr;
            }
            curr++;
        }

        return result;
    }
};