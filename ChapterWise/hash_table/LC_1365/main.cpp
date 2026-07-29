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
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int MAX = 502;
        vector<int> freq(MAX,0);
        for(int num : nums){
            freq[num+1]++;
        }

        for(int i=1;i<MAX;i++){
            freq[i]+=freq[i-1];
        }

        vector<int> ans; ans.reserve(nums.size());
        for(int num : nums){
            ans.push_back(freq[num]);
        }
        return ans;
    }
};