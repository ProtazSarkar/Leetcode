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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1)); //dp[i][pre]
        //base case
        for(int i=0;i<=n;i++){
            dp[n][i] = 0;
        }

        for(int i=n-1;i>=0;i--){
            for(int pre = -1;pre<n;pre++){
                int take = 0;
                if(pre == -1 || nums[i] > nums[pre]){
                    take = 1+dp[i+1][i+1];
                }

                int skip = dp[i+1][pre+1];
                dp[i][pre+1] = max(take,skip);
            }
        }

        return dp[0][0];
    }
};