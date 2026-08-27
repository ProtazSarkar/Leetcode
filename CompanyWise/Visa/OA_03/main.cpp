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
    int longestSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int left = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        priority_queue<pair<int,int>, vector<pair<int,int>>> maxheap;

        for (int right = 0; right < n; right++) {
            minheap.push({nums[right], right});
            maxheap.push({nums[right], right});

            // Shrink window if difference exceeds k
            while (maxheap.top().first - minheap.top().first > k) {
                left++;
                
                // Pop stale elements falling out of the left boundary
                while (!minheap.empty() && minheap.top().second < left) {
                    minheap.pop();
                }
                while (!maxheap.empty() && maxheap.top().second < left) {
                    maxheap.pop();
                }
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};