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
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int mx = 0;

        int ans = 0;
        for(int i=0;i<n-1;i++){
            mx = max(mx,nums[i]);
            if(mx > i+1){
                ans += locked[i] + locked[i+1];
                locked[i] = locked[i+1] = 0;
            }
        }

        if(ans > k){
            return -1;
        }

        vector<int> sorted;
        for(int x : nums){
            auto it = upper_bound(sorted.begin(),sorted.end(),x);
            ans += sorted.end() - it;
            sorted.insert(it,x);
        }

        return ans;
    }
};