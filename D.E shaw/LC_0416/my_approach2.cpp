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
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum=0;
        for(int num : nums){
            total_sum+=num;
        }

        if(total_sum%2) return false;

        int req_sum=total_sum/2;
        vector<vector<bool>> dp(n+1,vector<bool>(req_sum+1,false));

        for(int i=1 ; i<n ; i++){
            dp[i][nums[i]]=true;
            for(int j=0;j<req_sum;j++){
                if(j-nums[i]>=0){
                    dp[i][j]=dp[i-1][j] | dp[i-1][j-nums[i]];
                }
            }
        }

        return dp[n][req_sum];
    }
};