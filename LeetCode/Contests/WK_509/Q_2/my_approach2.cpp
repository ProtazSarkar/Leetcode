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
    bool canMakeSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(m<n) return false;

        vector<int> appear;
        appear.reserve(n);

        int j=0;int pre=j;
        for(int i=0;i<n;i++){
            j=pre;
            while(j<m && s[i]!=t[j]){
                j++;
            }
            if(j>=m){
                pre++;
                appear.push_back(-1);
            }else{
                pre = j;
                appear.push_back(j);
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(appear[i] == -1){
                cnt ++;
            }
        }

        return cnt < 2;
    }
};