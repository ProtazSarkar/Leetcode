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
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        if (occupiedIntervals.empty()) return {};

        // Step 1: Sort intervals by start time
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Step 2: Merge overlapping and touching intervals
        vector<vector<int>> merged;
        for (const auto& interval : occupiedIntervals) {
            if (merged.empty() || merged.back()[1] + 1 < interval[0]) {
                // No overlap and no touch, add as a new interval
                merged.push_back(interval);
            } else {
                // Overlap or touch, merge them
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        // Step 3: Remove the free interval [freeStart, freeEnd] from the merged intervals
        vector<vector<int>> ans;
        for (const auto& interval : merged) {
            int s = interval[0];
            int e = interval[1];

            // If the interval is completely inside the free range, skip it
            if (s >= freeStart && e <= freeEnd) {
                continue;
            }

            // If the interval is completely outside/unaffected by the free range
            if (e < freeStart || s > freeEnd) {
                ans.push_back({s, e});
                continue;
            }

            // If the free range splits the interval, we take the remaining valid parts
            if (s < freeStart) {
                ans.push_back({s, freeStart - 1});
            }
            if (e > freeEnd) {
                ans.push_back({freeEnd + 1, e});
            }
        }

        return ans;
    }
};