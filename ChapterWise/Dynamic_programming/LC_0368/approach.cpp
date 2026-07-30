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
    void solve(int i,vector<int>& nums,vector<int>& result,vector<int>& temp,int pre){
        if(i>=nums.size()){
            if(temp.size() > result.size()){
                result = temp;
            }
            return;
        }

        //take option
        if(pre == -1 || nums[i]%pre == 0){
            temp.push_back(nums[i]);
            solve(i+1,nums,result,temp,nums[i]);
            //backtrack for not take option
            temp.pop_back();
        }

        //not take
        solve(i+1,nums,result,temp,pre);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        vector<int> temp;

        sort(nums.begin(),nums.end());
        solve(0,nums,result,temp,-1);

        return result;
    }
};