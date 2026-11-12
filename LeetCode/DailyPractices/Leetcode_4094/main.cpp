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
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            unordered_map<int,int> count,order;
            int ok = 0;
            for(int j=i;j<n;j++){
                int x = nums[j];
                if(!order.count(x)){
                    order[x] = order.size()+1;
                }
                int cnt = ++count[x];
                int ord = order[x];

                if(ord < cnt){
                    break;
                }

                if(ord == cnt){
                    ok++;
                }

                if(ok == count.size()){
                    ans++;
                }
            }
        }

        return ans;
    }
};