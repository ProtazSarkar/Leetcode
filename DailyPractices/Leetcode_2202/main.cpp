class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {

        int n = nums.size();

        // special case
        if(n==1 && k%2==1) return -1;
        if(k==0) return nums[0];

        priority_queue<int> pq;

        // store first k-1 removable elements
        for(int i=0;i<min(n,k-1);i++){
            pq.push(nums[i]);
        }

        int fromRemoved = pq.empty()? -1 : pq.top();

        int next = -1;
        if(k < n) next = nums[k];

        return max(fromRemoved, next);
    }
};