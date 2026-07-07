#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    int at_most(vector<int>& nums,int k){
        int n=nums.size();
        if(k<0) return 0;
        unordered_map<int,int> map;
        int res=0;

        int j=0;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            while(map.size()>k){
                map[nums[j]]--;
                if(map[nums[j]]==0){
                    map.erase(nums[j]);
                }
                j++;
            }
            res+=(i-j+1);
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return at_most(nums,k)-at_most(nums,k-1);
    }
};