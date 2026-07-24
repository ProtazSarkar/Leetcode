#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2){
            return 0;
        }
        int ans=0;

        int left_max=0,right_max=0;

        int max_idx=0;
        for(int i=0;i<n;i++){
            if(height[i]>height[max_idx]){
                max_idx=i;
            }
        }
        
        for(int i=0;i<max_idx;i++){
            if(height[i]>left_max){
                left_max=height[i];
            }else{
                ans+=(left_max-height[i]);
            }
        }

        for(int i=n-1;i>=max_idx;i--){
            if(height[i]>right_max){
                right_max=height[i];
            }else{
                ans+=(right_max-height[i]);
            }
        }

        return ans;
    }
};