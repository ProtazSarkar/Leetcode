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
    int robRange(int start,int end,vector<int>& nums){
        int len = end - start +1;
        if(len <= 0)    return 0;

        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        for(int i=len-1;i>=start;i--){
            for(int pre = -1;pre<len;pre++){
                int take = 0;
                if(pre == -1 || i-pre > 1){
                    take = nums[i+start] + dp[i+1][i+1]; // solve(start+1,...,start) pre becomes now i
                }
                int skip = dp[i+1][pre+1];

                dp[i][pre+1] = max(take,skip);
            }
        }
        return dp[start][0];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int start_0 = robRange(0,n-2,nums);
        int start_1 = robRange(1,n-1,nums);

        return max(start_0,start_1);
    }
};