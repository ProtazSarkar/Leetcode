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
    bool is_same(vector<int>& a,vector<int>& b){
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> encode(26,0);
        for(char c : p){
            encode[c-'a']++;
        }

        vector<int> ans;
        vector<int> count(26,0);
        int win = p.length();

        int start = 0;
        for(int end = 0; end< s.length(); end++){
            int i = s[end] - 'a';
            count[i]++;
            if(end-start+1 < win)   continue;
            if(is_same(encode,count)){
                ans.push_back(start);
            }
            
            count[s[start++] - 'a']--;
        }
        return ans;
    }
};