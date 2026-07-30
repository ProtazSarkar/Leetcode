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
    long long solve(vector<int>& nums,int i,bool t){
        if(i >= nums.size()){
            return 0;
        }

        long long take ;
        if(t){
            take = solve(nums,i+1,!t) + nums[i];
        }else{
            take = solve(nums,i+1,!t) - nums[i];
        }

        long long skip = solve(nums,i+1,t);

        return max(take,skip);
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        return solve(nums,0,true);
    }
};