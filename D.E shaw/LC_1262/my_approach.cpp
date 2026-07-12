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
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int num : nums){
            sum+=num;
        }

        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j-nums[i-1] >= 0){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }

        int max_s=0;
        for(int i=0;i<=sum;i+=3){
            if(dp[n][i]){
                max_s=i;
            }
        }

        return max_s;
    }
};