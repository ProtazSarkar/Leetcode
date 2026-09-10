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
    bool is_possible(int cap,vector<int>& weights,int day){
        int sum = 0;
        int count = 0;
        for(int w : weights){
            if(w > cap )    return false;
            sum += w;
            if(sum > cap){
                sum = w;
                count++;
            }
        }
        return count+1 <= day;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 1;
        int right = 0;
        for(int w : weights){
            right+=w;
        }

        int ans = 0;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(is_possible(mid,weights,days)){
                ans = mid;
                right=mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};