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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nextSmaller(n);
        vector<int> preSmaller(n);

        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                nextSmaller[i]=n;
            }else{
                nextSmaller[i]=s.top();
            }
            s.push(i);
        }

        while(!s.empty())   s.pop();

        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                preSmaller[i]=-1;
            }else{
                preSmaller[i]=s.top();
            }
            s.push(i);
        }

        int ans=-1e9;
        for(int i=0;i<n;i++){
            int a=heights[i] * (nextSmaller[i]-preSmaller[i]-1);
            ans=max(ans,a);
        }
        return ans;
    }
};