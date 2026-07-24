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
    bool cmp(string s1,string s2){
        int n=s1.length();
        int m=s2.length();

        int size=min(n,m);
        for(int i=0;i<size;i++){
            if(s1[i]==s2[i]){
                continue;
            }else{
                return s1[i]<s2[i];
            }
        }

        return n<m;
    }
public:
    string smallestSubsequence(string s) {
        set<char> unique;
        for(char c : s){
            unique.insert(c);
        }

        set<char> collec;
    }
};