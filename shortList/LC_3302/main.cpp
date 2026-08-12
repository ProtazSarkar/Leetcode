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
    vector<int> validSequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<int> dp(n+1,0);
        int j=m-1;
        for(int i=n-1;i>=0;i--){
            if(j>=0 && s[i] == t[j]){
                dp[i] = dp[i+1] + 1;
                j--;
            }else{
                dp[i] = dp[i+1];
            }
        }

        vector<int> ans;
        j=0;
        bool canChange = true;
        for(int i=0;i<n && j<m;i++){
            int req = m-j-1;
            if(s[i]==t[j]){
                ans.push_back(i);
                j++;
            }else{
                if(canChange && dp[i+1] >= req){
                    ans.push_back(i);
                    j++;
                    canChange = false;
                }
            }
        }

        if(j == m){
            return ans;
        }
        return {};
    }
};