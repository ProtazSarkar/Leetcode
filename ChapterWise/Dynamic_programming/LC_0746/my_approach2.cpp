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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minimun_cost_from(n+2);

        //base case -> already reach to the end then need no cost
        minimun_cost_from[n+1] = 0;
        minimun_cost_from[n] = 0;

        for(int i=n-1;i>=0;i--){
            int take_one_step = cost[i] + minimun_cost_from[i+1];
            int take_two_step = cost[i] + minimun_cost_from[i+2];

            minimun_cost_from[i] = min(take_one_step,take_two_step);
        }

        return min(minimun_cost_from[0],minimun_cost_from[1]);
    }
};