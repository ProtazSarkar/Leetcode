#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> arr=nums;
        for(int i=0;i<n;i++){
            arr.push_back(nums[i]);
        }

        int t=x;
        int j=0;
        for(int i=0;i<arr.size();i++){
            t-=arr[i];
            if(t==0){
                return (i-j);
            }
            while(t<0){
                t+=arr[j];
                j++;
            }
        }
        return -1;
    }
};