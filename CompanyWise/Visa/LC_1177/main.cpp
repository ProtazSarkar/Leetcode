#include <vector>
#include <string>

class Solution {
public:
    std::vector<bool> canMakePaliQueries(std::string s, std::vector<std::vector<int>>& queries) {
        int n = s.length();
        // pref[i] stores the bitmask of character parities for s[0...i-1]
        std::vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] ^ (1 << (s[i] - 'a'));
        }

        std::vector<bool> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int left = q[0];
            int right = q[1];
            int k = q[2];

            // XOR gives the bitmask of parities for s[left...right]
            int mask = pref[right + 1] ^ pref[left];

            // Count how many bits are set (number of odd-frequency characters)
            int odd_count = __builtin_popcount(mask);

            // We need odd_count / 2 replacements
            answer.push_back((odd_count / 2) <= k);
        }

        return answer;
    }
};