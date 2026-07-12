#include <iostream>
#include <sstream>

// Containers
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>

// Associative Containers (Trees/Hashes)
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

// Algorithms & Utilities
#include <algorithm>
#include <numeric>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
    const int INF=1e9;
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();

        vector<vector<int>> dp(m+1,vector<int>(n+1,INF));
        for(int i = 0 ; i<=m;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=i;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    // no operation need
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int del=dp[i-1][j]; //go back to the state of word1 previous prefix , then come to the current state
                    int insert=dp[i][j-1]; //go back to the state of word2 previous prefix , then come to the current state
                    int replace=dp[i-1][j-1];//go back to the state of previous prefix of both word 1 and 2 , then come to the current state

                    dp[i][j]=min({insert,del,replace})+1;
                }
            }
        }

        return dp[m][n];
    }
};