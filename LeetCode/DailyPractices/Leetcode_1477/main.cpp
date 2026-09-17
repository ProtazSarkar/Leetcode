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
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // minLen[i] stores the minimum length of a subarray with sum = target 
        // within the prefix arr[0...i]
        vector<int> minLen(n, INT_MAX);
        
        int left = 0, sum = 0;
        int res = INT_MAX;
        int minSoFar = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left++];
            }
            
            if (sum == target) {
                int currLen = right - left + 1;
                
                // If there is a valid non-overlapping subarray to the left
                if (left > 0 && minLen[left - 1] != INT_MAX) {
                    res = min(res, currLen + minLen[left - 1]);
                }
                
                // Update the minimum length ending at or before 'right'
                minSoFar = min(minSoFar, currLen);
            }
            minLen[right] = minSoFar;
        }

        return res == INT_MAX ? -1 : res;
    }
};