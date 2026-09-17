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
    pair<int,int> solve(int i,int pre,vector<int>& nums,vector<vector<pair<int,int>>>& dp){
        if(i == nums.size()){
            return {0,1}; // base case 
        }

        if(dp[i][pre+1].first != -1){
            return dp[i][pre+1];
        }

        auto skip = solve(i+1,pre,nums,dp);
        int maxlen = skip.first;
        int count = skip.second;

        if(pre == -1 || (nums[pre] < nums[i])){
            auto take = solve(i+1,i,nums,dp);
            int takelen = take.first+1;
            int takecount = take.second;

            if(maxlen < takelen){
                maxlen = takelen;
                count = takecount;
            }
            else if(maxlen == takelen){
                count+=takecount;
            }
        }

        return dp[i][pre+1] = {maxlen,count};
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n+1,{-1,-1}));

        auto ans = solve(0,-1,nums,dp);
        return ans.second;
    }
};