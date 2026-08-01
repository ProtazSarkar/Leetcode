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
    bool solve(int start,int end,vector<int>& nums,int score1,int score2,bool turn1){
        if(start > end){
            return score1 >= score2;
        }

        // we have two option pick the first one or last one 
        bool first,last;
        if(turn1){
            first = solve(start+1,end,nums,score1+nums[start],score2,!turn1);
            last = solve(start,end-1,nums,nums[end]+score1,score2,!turn1);
        }else{
            first = solve(start+1,end,nums,score1,score2+nums[start],!turn1);
            last = solve(start,end-1,nums,score1,score2+nums[end],!turn1);
        }

        return (turn1) ? (first || last) : (first && last);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(0,nums.size()-1,nums,0,0,true);
    }
};