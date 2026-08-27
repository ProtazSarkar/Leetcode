# README - Sum of "Peak" Elements

## Problem Statement
Given an array `arr` of integers, find the sum of all elements that are strictly greater 
than their immediate neighbors.

- For the first element (index 0), its only neighbor is `arr[1]`.
- For the last element (index n-1), its only neighbor is `arr[n-2]`.
- For an array of length 1, the single element is considered a peak.

## Example
Input: arr = [2, 1, 6, 7, 4, 5, 1]
Output: 14
Explanation: Peaks are at indices 0 (val: 2), 3 (val: 7), and 5 (val: 5). Sum = 2 + 7 + 5 = 14.

## Function Template (Python 3)
class Solution:
    def sumOfPeaks(self, arr: list[int]) -> int:
        # TODO: Implement your solution here
        pass

## Function Template (C++)
#include <vector>

class Solution {
public:
    int sumOfPeaks(std::vector<int>& arr) {
        // TODO: Implement your solution here
        return 0;
    }
};