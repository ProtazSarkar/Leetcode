#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    const int INF=1e9+7;
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;

        int ans=-INF;
        while(left<=right){
            int width=right-left;
            int h=min(height[left],height[right]);
            ans=max(ans,(h*width));
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }

        return ans;
    }
};