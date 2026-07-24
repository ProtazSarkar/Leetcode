#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map;
        int ans=0;

        int j=0;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            if(map.size()==k){
                ans++;
            }
            if(map.size()>k){
                map.erase(nums[i]);
                while(map.size()==k){
                    ans++;
                    j++;
                    map[nums[j]]--;
                    if(map[nums[j]==0]){
                        map.erase(nums[j]);
                    }
                }
                map[nums[i]]++;
            }
        }
        return ans;

    }
};