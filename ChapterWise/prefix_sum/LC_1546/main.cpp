#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        int left = 0;
        unordered_map<int, int> first_seen;

        // Base case: prefix sum 0 occurs at virtual index -1
        first_seen[0] = -1;

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int right = 0; right < n; right++) {
            int req = prefix[right + 1] - target; // Fixed typo: target

            if (first_seen.find(req) != first_seen.end()) {
                int seen = first_seen[req];
                
                // Compare with left - 1 to allow subarrays starting at 'left'
                if (seen >= left - 1) {
                    ans++;
                    left = right + 1; // Move left past the current right index
                }
            }

            // Only store prefix[right + 1] if not already present,
            // or keep updating as needed for index tracking
            first_seen[prefix[right + 1]] = right;
        }

        return ans;
    }
};