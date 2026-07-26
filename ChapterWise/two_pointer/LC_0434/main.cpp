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
    // Helper function to calculate the next index safely in a circular array
    int getNextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        int nextIndex = (i + nums[i]) % n;
        if (nextIndex < 0) {
            nextIndex += n; // Handle negative wrapping
        }
        return nextIndex;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue; // Already processed/marked path

            int slow = i;
            int fast = i;

            // Check if the cycle moves in a consistent direction and hasn't hit a dead end (0)
            while (nums[i] * nums[fast] > 0 && nums[i] * nums[getNextIndex(nums, fast)] > 0) {
                slow = getNextIndex(nums, slow);
                fast = getNextIndex(nums, getNextIndex(nums, fast));

                if (slow == fast) {
                    // Check for self-loop (cycle length == 1)
                    if (slow == getNextIndex(nums, slow)) {
                        break;
                    }
                    return true; // Valid cycle found
                }
            }

            // Optimization: Mark all elements along this checked path as 0 
            // so we don't redundantly re-process them.
            int curr = i;
            int val = nums[i];
            while (nums[curr] * val > 0) {
                int next = getNextIndex(nums, curr);
                nums[curr] = 0;
                curr = next;
            }
        }

        return false;
    }
};