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
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n,-1);
        
        int pre = -1;int next ;
        // inti the next pointer
        for(int i=0;i<n;i++){
            if(s[i] == c){
                next = i;break;
            }
        }

        for(int i=0;i<n;i++){
            int distance;
            //calculate the distance 
            if(pre!=-1 && next!=n){
                distance = min(i-pre , next-i);
            }
            else if(pre!=-1){
                distance = i-pre;
            }
            else if(next!=n){
                distance=next-i;
            }

            //store the d9stance to the answer
            ans[i]=distance;

            //it we reach the end point the find the next pair 
            if(i==next){
                pre = next;
                while(next<n && s[next]!=c){
                    next++;
                }
            }
        }

        return ans;

    }
};