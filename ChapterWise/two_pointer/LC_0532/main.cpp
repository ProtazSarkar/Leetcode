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
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num :nums){
            freq[num]++;
        }

        int ans = 0;
        for(auto p : freq){
            int num = p.first;
            int count = p.second;
            if(k==0){
                if(freq[num]>1){
                    ans++;
                }
            }else{
                if(freq.find(num+k)!=freq.end()){
                    ans++;
                }
            }
        }

        return ans;
    }
};