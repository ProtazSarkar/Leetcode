#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    struct cmp
    {
        bool operator()(vector<int>& a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }else{
                return a[0]<b[0];
            }
        }
    };
    
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp());
        int ans=0;
        int maxEnd=-1;

        for(auto interval : intervals){
            if(interval[1]>maxEnd){
                ans++;
                maxEnd=interval[1]; 
            }
        }

        return ans;
    }
};