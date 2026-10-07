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
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        long long inf = 1e18;
        
        // State tracking:
        // s0: max alternating sum ending with '+' with 0 deletions
        // s1: max alternating sum ending with '-' with 0 deletions
        // s2: max alternating sum ending with '+' with 1 deletion
        // s3: max alternating sum ending with '-' with 1 deletion
        
        long long s0 = nums[0];
        long long s1 = -inf;
        long long s2 = -inf;
        long long s3 = -inf;
        
        long long ans = nums[0];
        
        for (int i = 1; i < n; i++) {
            long long x = nums[i];
            
            long long p_s0 = s0;
            long long p_s1 = s1;
            long long p_s2 = s2;
            long long p_s3 = s3;
            
            // 0 deletions transitions (Kadane's style for alternating sums)
            s0 = max(x, p_s1 + x);
            s1 = p_s0 - x;
            
            // 1 deletion transitions:
            // Option A: Delete current element x (transitions from 0-del to 1-del states)
            long long del_from_s0 = p_s0; 
            long long del_from_s1 = p_s1; 
            
            // Option B: Keep current element x, having already deleted an element earlier
            long long keep_s2 = (p_s3 != -inf) ? p_s3 + x : -inf;
            long long keep_s3 = (p_s2 != -inf) ? p_s2 - x : -inf;
            
            s2 = max({x, del_from_s0, keep_s2});
            s3 = max({del_from_s1, keep_s3});
            
            ans = max({ans, s0, s1, s2, s3});
        }
        
        return ans;
    }
};