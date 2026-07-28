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
    vector<int> encoded(string s){
        vector<int> result(26,0);
        for(char c : s){
            int val = c-'a';
            result[val]++;
        }
        return result;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> m;
        for(string s : strs){
            vector<int> encode = encoded(s);
            m[encode].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(m.size());

        for(auto pair : m){
            ans.push_back(pair.second);
        }

        return ans;
    }
};