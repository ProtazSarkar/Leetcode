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
    int solve(vector<int>& cost,int i,int curr_cost){
        if(i>=cost.size())    return curr_cost;
        int step_one = solve(cost,i+1,curr_cost+cost[i]);
        int step_two = solve(cost,i+2,curr_cost+cost[i]);

        return min(step_one,step_two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int start_from_0 = solve(cost,0,0);
        int start_from_1 = solve(cost,1,0);

        return min(start_from_0,start_from_1);
    }
};