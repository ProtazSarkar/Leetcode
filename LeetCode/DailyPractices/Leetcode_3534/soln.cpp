#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // 1. Store pairs of (value, original_index) and sort by value
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        sort(sorted_nums.begin(), sorted_nums.end());

        // Map original index to its new position in the sorted array
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[sorted_nums[i].second] = i;
        }

        // 2. Compute 1-step furthest jump using two pointers
        int LOG = 18; // Since 2^17 = 131072 > 10^5
        vector<vector<int>> nxt(LOG, vector<int>(n));
        
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && sorted_nums[r].first - sorted_nums[l].first <= maxDiff) {
                r++;
            }
            nxt[0][l] = r - 1; // Furthest reachable index from 'l' in 1 jump
        }

        // 3. Build Binary Lifting Table
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < n; ++i) {
                nxt[k][i] = nxt[k - 1][nxt[k - 1][i]];
            }
        }

        // Identify connected components to quickly check if a path exists at all
        vector<int> comp(n, 0);
        int c_id = 0;
        comp[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (sorted_nums[i].first - sorted_nums[i - 1].first > maxDiff) {
                c_id++;
            }
            comp[i] = c_id;
        }

        // 4. Process Queries
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (u > v) swap(u, v); // Ensure we always jump from left to right

            // If they aren't in the same connected component, no path exists
            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            // Lift up to find the minimum steps
            int steps = 0;
            int curr = u;
            for (int k = LOG - 1; k >= 0; --k) {
                if (nxt[k][curr] < v) {
                    curr = nxt[k][curr];
                    steps += (1 << k);
                }
            }
            
            // One final jump is needed to reach or cross 'v'
            ans.push_back(steps + 1);
        }

        return ans;
    }
};