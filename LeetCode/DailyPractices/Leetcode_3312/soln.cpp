#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<int> gcdValues(std::vector<int>& nums, std::vector<long long>& queries) {
        int mx = 0;
        for (int x : nums) mx = std::max(mx, x);

        // Count frequency of each number
        std::vector<int> cnt(mx + 1, 0);
        for (int x : nums) cnt[x]++;

        // cnt_g[i] will store the number of pairs with GCD exactly i
        std::vector<long long> cnt_g(mx + 1, 0);

        // Iterate backwards using the inclusion-exclusion principle
        for (int i = mx; i >= 1; --i) {
            long long multiples_count = 0;
            for (int j = i; j <= mx; j += i) {
                multiples_count += cnt[j];
            }

            // Total pairs where both numbers are multiples of i
            long long total_pairs = (multiples_count * (multiples_count - 1)) / 2;

            // Subtract pairs where the GCD is a multiple of i (2i, 3i, ...)
            for (int j = 2 * i; j <= mx; j += i) {
                total_pairs -= cnt_g[j];
            }

            cnt_g[i] = total_pairs;
        }

        // Build prefix sum array
        // prefix_sum[i] will store total count of pairs with GCD <= i
        std::vector<long long> prefix_sum(mx + 1, 0);
        for (int i = 1; i <= mx; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + cnt_g[i];
        }

        // Answer queries
        std::vector<int> answer;
        answer.reserve(queries.size());
        for (long long q : queries) {
            // Find the first index where prefix_sum[idx] > q
            auto it = std::upper_bound(prefix_sum.begin(), prefix_sum.end(), q);
            answer.push_back(std::distance(prefix_sum.begin(), it));
        }

        return answer;
    }
};