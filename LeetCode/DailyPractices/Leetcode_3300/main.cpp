#include<iostream>
#include<vector>

using namespace std;

class Solution {
    int digitSum(int n){
        if (n==0)   return 0;
        return n%10 + digitSum(n/10);
    }
public:
    int minElement(vector<int>& nums) {
        int ans=1e9;
        for (int n:nums){
            ans=min(ans,digitSum(n));
        }
        return ans;
    }
};