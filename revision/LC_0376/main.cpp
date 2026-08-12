class Solution {
    int memo[1001][1002][2];
    int solve(int i,int pre_idx,vector<int>& nums,int turn){
        if(i >= nums.size()){
            return 0;
        }
        int pre_key = pre_idx+1;
        if(memo[i][pre_key][turn] != -1)    return memo[i][pre_key][turn];
        int take = 0;
        if(pre_idx == -1 ||(nums[i]!=nums[pre_idx]) && (nums[i]-nums[pre_idx] > 0)^turn){
            take = 1+solve(i+1,i,nums,!turn);
        }
        int skip = solve(i+1,pre_idx,nums,turn);
        return memo[i][pre_key][turn] = max(take,skip);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        int start_up = solve(0,-1,nums,0);
        memset(memo,-1,sizeof(memo));
        int start_down = solve(0,-1,nums,1);
        return max(start_up,start_down);
    }
};