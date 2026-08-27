#include<vector>
using namespace std;

class Solution {
    int atmost(vector<int> &nums,int k){
        int n = nums.size();
        int ret = 0;

        int left = 0;
        int odd_count =0;

        for(int i=0;i<n;i++){
            if(nums[i] % 2 == 1){
                odd_count++;
            }

            while(odd_count > k){
                if(nums[left] %2 == 1){
                    odd_count --;
                }
                left ++;
            }

            ret += (i-left +1);
        }
        return ret;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};