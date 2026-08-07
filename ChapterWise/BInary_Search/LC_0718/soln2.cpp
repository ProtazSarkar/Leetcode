#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int left = 0, right = std::min(nums1.size(), nums2.size());
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == 0) {
                left = mid + 1;
                continue;
            }
            if (check(mid, nums1, nums2)) {
                ans = mid;
                left = mid + 1; // Try to find a longer length
            } else {
                right = mid - 1; // Try a smaller length
            }
        }
        return ans;
    }

private:
    bool check(int len, const std::vector<int>& nums1, const std::vector<int>& nums2) {
        long long MOD = 1e9 + 7;
        long long BASE = 101;
        
        // Compute base^(len-1) % MOD
        long long power = 1;
        for (int i = 0; i < len - 1; ++i) {
            power = (power * BASE) % MOD;
        }

        // Hash all windows of length 'len' in nums1
        std::unordered_set<long long> hashes1;
        long long hash = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            hash = (hash * BASE + nums1[i]) % MOD;
            if (i >= len) {
                hash = (hash - nums1[i - len] * power) % MOD;
                if (hash < 0) hash += MOD;
            }
            if (i >= len - 1) {
                hashes1.insert(hash);
            }
        }

        // Hash windows of length 'len' in nums2 and check for collision
        hash = 0;
        for (int i = 0; i < nums2.size(); ++i) {
            hash = (hash * BASE + nums2[i]) % MOD;
            if (i >= len) {
                hash = (hash - nums2[i - len] * power) % MOD;
                if (hash < 0) hash += MOD;
            }
            if (i >= len - 1) {
                if (hashes1.count(hash)) {
                    return true;
                }
            }
        }

        return false;
    }
};