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
        int maxReach = 0;

        for (int i = 0; i < n; i++) {
            // If the current index is beyond the maximum reach possible, 
            // we can't move any further.
            if (i > maxReach) {
                return false;
            }
            
            // Update the maximum reachable index from the current position
            maxReach = max(maxReach, i + nums[i]);
            
            // Early exit if we can already reach or exceed the last index
            if (maxReach >= n - 1) {
                return true;
            }
        }

        return true;
    }
};