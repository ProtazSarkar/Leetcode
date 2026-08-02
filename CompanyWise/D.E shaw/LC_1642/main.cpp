class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int,vector<int>,greater<int>> minheap;
        
        int remaining = bricks;
        for(int i=0;i<n-1;i++){
            int diff = heights[i+1] - heights[i];
            if(diff <= 0)   continue;

            minheap.push(diff);
            if(minheap.size() > ladders){
                remaining -= minheap.top();
                minheap.pop();
            }
            if(remaining < 0){
                return i;
            }
        }
        return n-1;
    }
};