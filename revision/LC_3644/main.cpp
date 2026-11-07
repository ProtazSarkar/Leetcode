class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        bool sorted = true;
        for(int i=0;i<n;i++){
            if(nums[i] != i){
                sorted = false;
                break;
            }
        }

        if(sorted){
            return 0;
        }

        int ans = (1<<30) - 1;
        for(int i=0;i<n;i++){
            if(nums[i] != i){
                ans &= nums[i];
            }
        }
        return ans;
    }
};