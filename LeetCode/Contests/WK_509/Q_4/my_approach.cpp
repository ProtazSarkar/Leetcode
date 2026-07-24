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
    const int INF = 1e9;
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = -1;

        for(int i=0;i<n;i++){
            long long curr = nums[i];
            int left = i-1;
            int right = i+1;

            while(left >= 0 && right < n && nums[left]==nums[right]){
                curr+=(nums[left]+nums[right]);
                left--;
                right++;
            }
            ans=max(ans,curr);
        }
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                long long curr = 2* nums[i];
                int left = i-1;
                int right = i+2;

                while (left>=0 && right<n && nums[left]==nums[right])
                {
                    curr+=(nums[left]+nums[right]);
                    left--;
                    right++;
                }

                ans=max(ans,curr);
                
            }
        }

        return ans;
    }
};
