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
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> map(101);
        for(int i=0;i<n2;i++){
            map[nums2[i]].push_back(i);
        }

        int ans= 0;
        
        for(int i=0;i<n1;i++){
            for(int start : map[nums1[i]]){
                int j=start;int i1 = i;
                while(j<n2 && i1 < n1 && nums1[i1] == nums2[j]){
                    j++;
                    i1++;
                }
                int curr_len = (i1 - i);
                ans = max(ans,curr_len);
            }
        }

        return ans;
    }
};