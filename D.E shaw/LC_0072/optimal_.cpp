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
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<int> dp(n + 1, 0);
        
        // Base case: transforming empty word1 to word2
        for (int j = 0; j <= n; j++) dp[j] = j;
        
        for (int i = 1; i <= m; i++) {
            int prev = dp[0]; // Stores the diagonal element (dp[i-1][j-1])
            dp[0] = i;        // Base case for the beginning of each row
            
            for (int j = 1; j <= n; j++) {
                int temp = dp[j]; // Save the old value before it's overwritten
                
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = 1 + min({dp[j - 1], dp[j], prev}); // Insert, Delete, Replace
                }
                
                prev = temp; // Update diagonal for the next column
            }
        }
        
        return dp[n];
    }
};