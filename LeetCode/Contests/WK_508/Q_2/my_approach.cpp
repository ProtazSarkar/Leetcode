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
    struct cmp{
        bool operator()(const vector<int>& arr1,const vector<int>& arr2){
            if(arr1[0]==arr2[0]){
                return arr1[1]>arr2[1];
            }
            return arr1[0]<arr2[0];
        }
    };
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end(),cmp());

        vector<vector<int>> ans;
        for(auto interval : occupiedIntervals){
            int s=interval[0];
            int e=interval[1];

            if(s>=freeStart && e<=freeEnd)  continue;

            if(s>=freeStart){
                s=freeEnd++;
            }
            if(e<=freeEnd){
                e=freeStart--;
            }

            vector<int> temp = {s,e};
            ans.push_back(temp);
        }

        return ans;
    }
};