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
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();

        map<pair<int,int>,int> count;
        int base = 0;
        int mx_pair_count = 0;
        for(int i=0;i<n-1;i++){
            int a = min(nums[i],nums[i+1]);
            int b = max(nums[i],nums[i+1]);

            if(a == b){
                base ++;
            }else{
                count[{a,b}]++;
                if(mx_pair_count < count[{a,b}]){
                    mx_pair_count = count[{a,b}];
                }
            }
        }

        return base + mx_pair_count;
    }
};