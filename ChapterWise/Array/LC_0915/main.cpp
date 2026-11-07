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
    int partitionDisjoint(vector<int>& nums) {
        int left_max = nums[0];
        int curr_max = nums[0];

        int ans = 1;
        for(int i=1;i<nums.size();i++){
            curr_max = max(curr_max,nums[i]);
            if(nums[i] < left_max){
                left_max = curr_max;
                ans = i+1;
            }
        }
        return ans;
    }
};