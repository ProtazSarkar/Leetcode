class Solution {
    int memo[100001];

    bool solve(int i){
        if(i <= 0)  return false;
        if(memo[i] != -1)   return memo[i];

        for(int j=1;j*j <= i ;j++){
            if(!solve(i-j*j)){
                return memo[i] = 1;
            }
        }
        return memo[i] = 0;
    }
public:
    bool winnerSquareGame(int n) {
        memset(memo,-1,sizeof(memo));
        return solve(n);
    }
};