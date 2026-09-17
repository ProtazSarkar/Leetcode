class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            int left_greater = 0;
            int left_less = 0;

            for(int j=0;j<i;j++){
                if(nums[i] < nums[j]){
                    left_greater++;
                }else{
                    left_less ++;
                }
            }

            int right_greater =0;
            int right_less = 0;

            for(int j=i+1;j<n;j++){
                if(nums[i] < nums[j]){
                    right_greater++;
                }else{
                    right_less++;
                }
            }

            ans +=(left_less*right_greater) + (left_greater*right_less);
        }
        return ans;
    }
};