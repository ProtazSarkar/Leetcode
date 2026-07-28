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
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int t = n/3;
        vector<int> ans;
        ans.reserve(n);

        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n){
            int j=i;int count =0;
            while(j<n && nums[i] == nums[j]){
                j++;count++;
            }

            if(count > t){
                ans.push_back(nums[i]);
            }

            i=j;
        }
        
        return ans;
    }
};