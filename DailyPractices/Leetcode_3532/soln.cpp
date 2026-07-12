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
private:
    // Finds the furthest index we can jump to from 'curr'
    int get_max_jump(vector<int>& nums, int curr, int high, int maxDiff) {
        int left = curr, right = high, ans = curr;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] - nums[curr] <= maxDiff) {
                ans = mid;      // Valid jump found, try to find a further one
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    bool is_possible(vector<int>& nums, int l, int r, int maxDiff) {
        // Greedily jump as far right as possible until we reach or exceed 'r'
        while (l < r) {
            int next_l = get_max_jump(nums, l, r, maxDiff);
            if (next_l == l) return false; // Stuck! Cannot move forward
            l = next_l;
        }
        return true;
    }

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            ans.push_back(is_possible(nums, q[0], q[1], maxDiff));
        }
        return ans;
    }
};