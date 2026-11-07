#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        int curr_max = 0;
        int curr_min = 0;

        int max_sum = nums[0];
        int min_sum = nums[0];

        for(int x : nums){
            total_sum += x;

            curr_max = max(x,curr_max + x);
            max_sum = max(max_sum , curr_max);

            curr_min = min(x,curr_min + x);
            min_sum = min(min_sum , curr_min);
        }

        if(max_sum < 0){
            return max_sum;
        }

        return max(max_sum,total_sum - min_sum);
    }
};