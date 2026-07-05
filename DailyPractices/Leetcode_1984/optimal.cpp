#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        int min_diff = INT_MAX;

        for (int start = 0; start + k - 1 < arr.size(); start++) {
            int end = start + k - 1;
            min_diff = min(min_diff, arr[end] - arr[start]);
        }

        return min_diff;
    }
};

int main(){
	
	return 0;
}