class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScore(n+1,0);
        vector<bool> can_be_judge(n+1,true);
        for(auto t : trust){
            trustScore[t[1]]++;
            can_be_judge[t[0]] = false;
        }

        for(int i=1;i<=n;i++){
            if(trustScore[i] == n-1 && can_be_judge[i]){
                return i;
            }
        }
        return -1;
    }
};