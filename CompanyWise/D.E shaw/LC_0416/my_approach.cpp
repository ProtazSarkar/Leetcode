#include <iostream>
#include <sstream>

// Containers
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>

// Associative Containers (Trees/Hashes)
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

// Algorithms & Utilities
#include <algorithm>
#include <numeric>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
    bool solve(vector<int>& nums,int i,int curr_sum,int total_sum){
        if(i >= nums.size())    return false;
        if(curr_sum == total_sum/2)   return true;

        bool take=solve(nums,i+1,curr_sum+nums[i],total_sum);
        bool skip=solve(nums,i+1,curr_sum,total_sum);

        return skip | take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int total_sum=0;
        for(int num : nums){
            total_sum+=num;
        }

        if(total_sum%2) return false;
        return solve(nums,0,0,total_sum);
    }
};