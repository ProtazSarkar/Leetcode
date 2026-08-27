#include <vector>
#include <unordered_set>

class Solution {
    void backtrack(int index, const std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (current.size() >= 2) {
            result.push_back(current);
        }
        
        std::unordered_set<int> usedInCurrent;
        for (int i = index; i < nums.size(); i++) {
            // Check non-decreasing condition AND duplicate usage at this level
            if ((current.empty() || current.back() <= nums[i]) && !usedInCurrent.count(nums[i])) {
                current.push_back(nums[i]);
                usedInCurrent.insert(nums[i]);
                
                backtrack(i + 1, nums, current, result);
                current.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;

        backtrack(0, nums, curr, ans);
        return ans;
    }
};