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
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if(n<10)    return {};

        unordered_set<string> seen;
        unordered_set<string> repeted;
        for(int i =0;i<n-10;i++){
            string sub = s.substr(i,10);
            if(seen.count(sub)){
                repeted.insert(sub);
            }else{
                seen.insert(sub);
            }
        }

        return vector<string>(repeted.begin(),repeted.end());
    }
};