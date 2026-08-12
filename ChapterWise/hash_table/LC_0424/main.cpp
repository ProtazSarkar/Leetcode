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
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int j=0;
        int maxcount = 0;
        int maxlen = 0;

        for(int i=0;i<s.length();i++){
            freq[s[i]-'A']++;
            maxcount = max(maxcount,freq[s[i]-'A']);
            if((i-j+1) - maxcount > k){
                freq[s[j++]-'A']--;
            }
            maxlen = max(maxlen,(i-j+1));
        }

        return maxlen;
    }
};