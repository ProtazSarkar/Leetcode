#include <iostream>
#include <sstream>

// Containers
#include <vector>

using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        bool is_sorted = true;
        for(int i=0;i<n;i++){
            if(nums[i] !=i){
                is_sorted = false;
                break;
            }
        }

        if(is_sorted){
            return 0;
        }

        int ans = (1<<30)-1;
        for(int i=0;i<n;i++){
            if(nums[i] != i){
                ans &= nums[i];
            }
        }

        return ans;
    }
};