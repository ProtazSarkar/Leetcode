#include <iostream>
#include <vector>

class Solution {
    int solve(vector<int>& arr, int k, int idx,
              int picked, int currMin, int currMax) {

        // picked k elements → valid subset
        if (picked == k)
            return currMax - currMin;

        // ran out of elements → invalid
        if (idx == arr.size())
            return INT_MAX;

        // option 1: skip
        int skip = solve(arr, k, idx + 1,
                          picked, currMin, currMax);

        // option 2: pick
        int pick = solve(arr, k, idx + 1,
                          picked + 1,
                          min(currMin, arr[idx]),
                          max(currMax, arr[idx]));

        return min(skip, pick);
    }

public:
    int minimumDifference(vector<int>& nums, int k) {
        return solve(nums, k, 0, 0, INT_MAX, INT_MIN);
    }
};

int main(){
	
	return 0;
}