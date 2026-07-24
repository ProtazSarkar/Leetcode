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
    const int INF = 1e9;
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));
        
        // Base case: 0 coins needed to make amount 0
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++){          // Fix: i <= n to include all coins
            for(int j = 1; j <= amount; j++){ // Fix: loop up to 'amount', not 'n'
                
                // Scenario A: Do not take the coin (carry forward from previous row)
                dp[i][j] = dp[i-1][j]; 
                
                // Scenario B: Take the coin (if it fits)
                if(j - coins[i-1] >= 0){
                    // Fix: Look at dp[i] (current row) for infinite supply
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i-1]] + 1);
                }
            }
        }

        return (dp[n][amount] == INF) ? -1 : dp[n][amount];
    }
};