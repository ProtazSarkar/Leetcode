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
        int ans=0;

        int i=0,j=0;
        while(i<n-1 && height[i]<=height[i+1]){
            i++;
        }
        j=i;
        for(;i<n;i++){
            int k=j;
            while(height[i]>height[j]){
                ans+=(height[k]-height[j]);
                j++;
            }
        }

        i=n-1;
        while(i>=0 && height[i]<height[i-1]){
            i--;
        }
        j=i;
        for(;i>=0;i--){
            int k=j;
            while(height[i]>height[j]){
                ans+=(height[k]-height[j]);
                j--;
            }
        }

        return ans;
    }
};