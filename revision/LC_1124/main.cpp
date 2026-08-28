class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int ans = 0;

        unordered_map<int,int> seen;
        seen[0] = -1;

        int diff = 0;
        for(int i=0;i<n;i++){
            if(hours[i] > 8){
                diff++;
            }else{
                diff --;
            }
            if(diff > 0){
                ans = i+1;
            }
            else if(seen.find(diff-1) != seen.end()){
                ans = max(ans,(i-seen[diff-1]));
            }
            if(!seen.count(diff)){
                seen[diff] = i;
            }
        }

        return ans;
    }
};