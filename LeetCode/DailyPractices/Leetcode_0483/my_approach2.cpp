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
    
    bool solve(int start,int end,vector<int>& nums,int diff,int turn){
        if(start > end){
            return diff >= 0;
        }

        bool take_first,take_end;
        if(turn == 0){
            //player 1 turn
            take_first = solve(start+1,end,nums,diff+nums[start],1);
            take_end = solve(start,end-1,nums,diff+nums[end],1);
        }else{
            take_first = solve(start+1,end,nums,diff - nums[start],0);
            take_end = solve(start,end-1,nums,diff-nums[end],0);
        }

        return (turn == 0) ? (take_first || take_end) : (take_first && take_end);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(0,nums.size()-1,nums,0,0);
    }
};