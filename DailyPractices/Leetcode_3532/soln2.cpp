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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // g[i] will store the component ID for index i
        vector<int> g(n, 0);
        int component_id = 0;
        
        // One pass: If the gap between consecutive elements is > maxDiff, 
        // it means we cannot cross it. Start a new component group.
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                component_id++;
            }
            g[i] = component_id;
        }
        
        // Answer each query in O(1) time
        vector<bool> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            // If they belong to the same component, a path exists!
            ans.push_back(g[u] == g[v]);
        }
        
        return ans;
    }
};