#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        int max_i=0;
        int n_max=0;

        for(int i=0;i<n;i++){
            int start=i-k+1;
            if(nums[i]>= nums[max_i]){
                max_i=i;
                n_max=i+1;
            }
            if(n_max<=i && nums[i]>=nums[n_max]){
                n_max=i;
            }
            if(start>max_i){
                max_i=n_max;
                n_max++;
            }
            if(start < 0)   continue;

            ans.push_back(nums[max_i]);
        }

        return ans;
    }
};