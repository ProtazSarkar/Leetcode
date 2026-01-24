#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Step 1: Sort the array to enable greedy pairing
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int maxSum = 0;

        // Step 2: Pair the smallest (i) with the largest (n-1-i)
        for (int i = 0; i < n / 2; i++) {
            int currentPairSum = nums[i] + nums[n - 1 - i];
            maxSum = max(maxSum, currentPairSum);
        }

        return maxSum;
    }
};

int main(){
	
	return 0;
}