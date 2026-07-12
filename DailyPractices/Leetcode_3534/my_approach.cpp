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
    int solve(vector<int> nums,int maxDiff,int l,int r){
        if(l >= r)   return 0;

        int left=l;
        int right=r;
        int ans=left;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]-nums[l] <= maxDiff){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

        if(ans == l)   return -1;
        return 1+solve(nums,maxDiff,ans,r);
    }
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
    }
};