#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int lastInvalid = -1;
        int lastValid = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > right) {
                lastInvalid = i;
            }

            if (nums[i] >= left) {
                lastValid = i;
            }

            ans += max(0, lastValid - lastInvalid);
        }

        return ans;
    }
};
