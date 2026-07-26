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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int n = heaters.size();
        int ans = 0;

        int i=0;
        for(int house : houses){
            while(i+1 < n && abs(house - heaters[i]) >= abs(house - heaters[i+1])){
                i++;
            }

            int current_dis = abs(heaters[i]-house);
            ans = max(ans,current_dis);
        }

        return ans;
    }
};