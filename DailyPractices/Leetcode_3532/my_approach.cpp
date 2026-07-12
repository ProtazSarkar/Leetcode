#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Finds the furthest valid index we can jump to moving RIGHT from 'l'
    int maxJumpFromLeft(vector<int>& nums, int l, int h, int maxDiff) {
        int left = l;
        int right = h;
        int ans = l; // Default to current position if we can't move

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] - nums[l] <= maxDiff) {
                ans = mid;       // Valid jump found, try to look further right
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    // Finds the furthest valid index we can jump to moving LEFT from 'h'
    int maxJumpFromRight(vector<int>& nums, int l, int h, int maxDiff) {
        int left = l;
        int right = h;
        int ans = h; // Default to current position if we can't move

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[h] - nums[mid] <= maxDiff) {
                ans = mid;       // Valid jump found, try to look further left
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    bool is_possible(vector<int>& nums, int l, int r, int maxDiff) {
        // Base case: If left and right pointers meet or cross, a path exists
        if (l >= r) return true;

        int jump_left = maxJumpFromLeft(nums, l, r, maxDiff);
        int jump_right = maxJumpFromRight(nums, l, r, maxDiff);

        // If both sides can cross or meet each other, path is found
        if (jump_left >= jump_right) return true; 
        
        // If NEITHER side was able to make any progress forward, we are permanently stuck
        if (jump_left == l && jump_right == r) return false;

        // FIXED: Correctly invoking the recursion instead of using the comma operator
        return is_possible(nums, jump_left, jump_right, maxDiff); 
    }

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto q : queries) {
            int l = q[0];
            int r = q[1];
            ans.push_back(is_possible(nums, l, r, maxDiff));
        }
        return ans;
    }
};