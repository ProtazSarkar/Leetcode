class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int MAX = 502;
        vector<int> freq(MAX,0);
        for(int num : nums){
            freq[num+1]++;
        }

        for(int i=1;i<MAX;i++){
            freq[i]+=freq[i-1];
        }

        vector<int> ans; ans.reserve(nums.size());
        for(int num : nums){
            ans.push_back(freq[num]);
        }
        return ans;
    }
};