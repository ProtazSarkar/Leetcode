#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> flag(n,1);
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int l1=intervals[i][0];
                int h1=intervals[i][1];
                int l2=intervals[j][0];
                int h2=intervals[j][1];

                if(l1<=l2 && h1>=h2){
                    //remove the jth 
                    flag[j]=0;
                }
                else if(l2>=l1 && h2<=h1){
                    //remove i th term
                    flag[i]=0;
                }
            }
        }
        for(int f : flag){
            ans += f;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> interval={{1,4},{3,6},{2,8}};
    int ans=s.removeCoveredIntervals(interval);
    cout<<ans;
    return 0;
}