# README - Longest Valid Subsegment

## Problem Statement
Given an array of integers `nums` and a constraint integer `k`, find the length of the longest 
contiguous subarray where the absolute difference between the maximum and minimum elements 
within the subarray is at most `k`.

## Example
Input: nums = [8, 2, 4, 7], k = 4
Output: 2
Explanation: 
Subarray [2, 4] has max 4, min 2 -> diff = 2 <= 4 (length 2).
Subarray [4, 7] has max 7, min 4 -> diff = 3 <= 4 (length 2).

## Function Template (Python 3)
class Solution:
    def longestSubarray(self, nums: list[int], k: int) -> int:
        # TODO: Implement your solution here
        pass

## Function Template (C++)
#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int k) {
        // TODO: Implement your solution here
        return 0;
    }
};