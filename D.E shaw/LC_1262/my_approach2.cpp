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
        vector<int> dp={0,INT_MIN,INT_MIN};
        int n=nums.size();
        
        for(int num : nums){
            vector<int> next_dp=dp;
            for(int i=0;i<3;i++){
                if(next_dp[i]!=INT_MIN){
                    int new_sum=dp[i]+num;
                    int rem=new_sum%3;
                    next_dp[rem]=max(next_dp[i],new_sum);
                }
            }

            dp=next_dp;
        }

        return dp[0];
    }
};