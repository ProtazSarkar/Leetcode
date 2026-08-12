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
    int memo[201][201];
    int solve(int low,int high){
        if(low >= high) return 0;
        if(memo[low][high] != -1)   return memo[low][high];
        int ret = INT_MAX;
        for(int g=low;g<=high;g++){
            int cost_for_lower = g+solve(low,g-1);
            int cost_for_upper = g+solve(g+1,high);
            int max_cost = max(cost_for_lower,cost_for_upper);
            ret = min(ret,max_cost);
        }
        return memo[low][high] = ret;
    }
public:
    int getMoneyAmount(int n) {
        memset(memo,-1,sizeof(memo));
        return solve(1,n);
    }
};