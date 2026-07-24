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
    int maxActiveSectionsAfterTrade(string s) {
        int ans = 0;
        vector<int> zero_blocks;

        int count_0=0;
        int count_1=0;
        bool already_push = false;

        for(char c : s){
            if(c == '0'){
                count_0++;
                already_push = false;
            }else{
                if(!already_push){
                    zero_blocks.push_back(count_0);
                    already_push = true;
                }
                count_1++;
            }
        }
        ans=count_1;
        for(int i=1;i<zero_blocks.size();i++){
            ans = max(ans,(zero_blocks[i]+zero_blocks[i-1]+count_1));
        }

        return ans;
    }
};