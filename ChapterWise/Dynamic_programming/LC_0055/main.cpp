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
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        //dp create and base case define
        vector<int> can_reach(n,false);
        can_reach[0] = true;

        for(int i=0;i<n-1;i++){
            if(can_reach[i]){
                for(int j=0;j<nums[i];j++){
                    int next = min(n-1, i+j+1);
                    can_reach[next] = true;
                }
            }
        }

        return can_reach[n-1];
    }
};