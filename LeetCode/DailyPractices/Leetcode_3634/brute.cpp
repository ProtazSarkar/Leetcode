#include<iostream>
using namespace std;

class Solution {
    int solve(vector<int>& arr,int l,int r,int k){
        if(l>=r || arr[l]*k>=arr[r])    return 0;
        
        //slide the left and ckeck
        int left=1+solve(arr,l+1,r,k);
        //slide the right and check
        int right=1+solve(arr,l, r-1, k);
        return min(left,right);
    }
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()) ;
        return solve(nums,0,nums.size()-1,k);
    }
};