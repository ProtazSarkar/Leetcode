# README - Optimal Server Allocation

## Problem Statement
You are given an array `load` representing tasks to execute across `k` servers. Each element `load[i]` 
represents the weight of the $i$-th task. Distribute all tasks into `k` non-empty contiguous partitions 
such that the maximum sum among all partitions is minimized.

Return the minimum possible maximum load assigned to any server.

## Example
Input: load = [7, 2, 5, 10, 8], k = 2
Output: 18
Explanation: Partition into [7, 2, 5] and [10, 8]. Max sum is max(14, 18) = 18.

## Function Template (Python 3)
class Solution:
    def splitArray(self, load: list[int], k: int) -> int:
        # TODO: Implement your solution here
        pass

## Function Template (C++)
#include <vector>

class Solution {
public:
    int splitArray(std::vector<int>& load, int k) {
        // TODO: Implement your solution here
        return 0;
    }
};