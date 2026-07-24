#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    struct cmp
    {
        bool operator()(const vector<int>&a,const vector<int>&b)const{
            if(a[0]==b[0]){
                return a[1]>b[1];
            }else{
                return a[0]<b[0];
            }
        }
    };
    
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n =intervals.size();
        sort(intervals.begin(),intervals.end(),cmp());
        int ans=0;
        vector<int> flag(n,1);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(flag[i] && flag[j] && intervals[i][1]>=intervals[j][1]){
                    flag[j]=0;
                }
            }
        }

        for(auto f : flag){
            ans+=f;
        }
        return ans;
    }
};