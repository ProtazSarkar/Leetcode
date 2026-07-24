#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    int max=0;
    int count=0;
    
    void solve(vector<int>& nums,int i,int current_or){
        if(i>=nums.size()){
            if(current_or>max){
                max=current_or;
                count=1;
            }else if(current_or == max){
                count++;
            }
            return ;
        }

        //Take
        solve(nums,i+1,current_or | nums[i]);

        //Skip
        solve(nums,i+1,current_or);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        solve(nums,0,0);
        return count;
    }
};