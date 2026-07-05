#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    long long solve(vector<int>& nums,vector<long long> trans_arr){
        int n=nums.size();

        long long dp0=LLONG_MIN/2;
        long long dp1=LLONG_MIN/2;
        long long dp2=LLONG_MIN/2;

        long long global_max=LLONG_MIN/2;

        for(int i=0;i<n;i++){
            long long orig=nums[i];
            long long trans=trans_arr[i];

            long long next_dp2=max({orig,dp2+orig,dp1+orig});
            long long next_dp1=max({trans,dp1+trans,dp0+trans});
            long long next_dp0=max(orig,dp0+orig);

            dp0=next_dp0;
            dp1=next_dp1;
            dp2=next_dp2;

            global_max=max({global_max,dp0,dp1,dp2});
        }
        return global_max;
    }
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> mul_arr(n);
        vector<long long> div_arr(n);

        for(int i=0;i<n;i++){
            mul_arr[i]=(long long)nums[i]*k;
            div_arr[i]=(long long)nums[i]/k;
        }

        long long max_mul=solve(nums,mul_arr);
        long long max_div=solve(nums,div_arr);

        return max(max_mul,max_div);
    }
};