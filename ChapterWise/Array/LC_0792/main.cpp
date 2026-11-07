#include <algorithm>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;

        vector<vector<int>> char_idxs(26);

        for (int i = 0; i < s.size(); i++) {
            char_idxs[s[i] - 'a'].push_back(i);
        }

        for (const string& w : words) {
            int curr_idx = -1;
            bool is_sub = true;

            for (char c : w) {
                auto& idxs = char_idxs[c - 'a'];

                auto it = upper_bound(
                    idxs.begin(), idxs.end(), curr_idx
                );

                if (it == idxs.end()) {
                    is_sub = false;
                    break;
                }

                curr_idx = *it;
            }

            if (is_sub) {
                count++;
            }
        }

        return count;
    }
};
