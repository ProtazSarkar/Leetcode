class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int diff = 0;
        
        unordered_map<int,int> seen;
        seen[0] = -1;
        
        for(int i=0;i<n;i++){
            if(nums[i] == 0)    diff ++;
            if(nums[i] == 1)    diff--;

            if(seen.count(diff)){
                ans = max(ans,i-seen[diff]);
            }else{
                seen[diff] = i;
            }
        }
        return ans;
    }
};