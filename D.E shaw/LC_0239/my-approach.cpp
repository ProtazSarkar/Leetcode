#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    const int INF=1e9;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int max_idx=-1;
        vector<int> ans;

        for(int i=k-1;i< n;i++){
            int w_start=i-k+1;
            if(w_start > max_idx){
                max_idx=w_start;
                for(int j=w_start;j<=i;j++){
                    if(nums[j]>nums[max_idx]){
                        max_idx=j;
                    }
                }
            }
            else if(nums[i]>nums[max_idx]){
                max_idx=i;
            }
            ans.push_back(nums[max_idx]);
        }

        return ans;
    }
};