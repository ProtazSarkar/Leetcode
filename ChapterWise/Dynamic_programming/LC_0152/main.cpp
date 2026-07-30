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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int current_max_product = nums[0];
        int current_min_product = nums[0];
        int result = nums[0];

        for(int i=0;i<n;i++){
            if(nums[i] < 0){
                swap(current_max_product,current_min_product);
            }

            current_max_product = max(nums[i],current_max_product * nums[i]);
            current_min_product = min(nums[i],current_min_product * nums[i]);

            result = max(current_max_product,current_min_product);
        }

        return result;
    }
};