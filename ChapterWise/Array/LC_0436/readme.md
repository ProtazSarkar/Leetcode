# Find Right Interval

**LeetCode 436**

## Problem Statement

You are given an array of intervals, where `intervals[i] = [start_i, end_i]`.
For each interval `i`, find the index of the interval whose start is the
smallest value that is greater than or equal to `end_i`. This is called the
right interval for `i`.

Return an array containing the right-interval index for each input interval.
If no such interval exists, use `-1`.

### Example

```text
Input:  intervals = [[3, 4], [2, 3], [1, 2]]
Output: [-1, 0, 1]
```

- For `[3, 4]`, no interval starts at or after `4`.
- For `[2, 3]`, `[3, 4]` is the right interval, at index `0`.
- For `[1, 2]`, `[2, 3]` is the right interval, at index `1`.

## Approach: Sort and Binary Search

For every interval, save its start value together with its original index.
Sort these pairs by start value so the earliest qualifying start can be found
with binary search.

For each interval:

1. Search for the first sorted start value greater than or equal to its end.
2. Return the original index paired with that start value.
3. If no such start exists, return `-1`.

The implementation's recursive binary search explores the left half after
finding a qualifying start, so it can return the smallest qualifying start.
The original indices are retained in the pairs so sorting does not change the
indices in the answer.

## C++ Implementation

```cpp
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    int bs(int target, int left, int right,
           vector<pair<int, int>>& starts) {
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if (starts[mid].first == target) {
            return starts[mid].second;
        }

        if (starts[mid].first < target) {
            return bs(target, mid + 1, right, starts);
        }

        int leftAnswer = bs(target, left, mid - 1, starts);
        return leftAnswer != -1 ? leftAnswer : starts[mid].second;
    }

public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts;
        starts.reserve(n);

        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }

        sort(starts.begin(), starts.end());
        int largestStart = starts[n - 1].first;

        vector<int> answer;
        answer.reserve(n);

        for (const auto& interval : intervals) {
            int end = interval[1];
            if (end > largestStart) {
                answer.push_back(-1);
            } else {
                answer.push_back(bs(end, 0, n - 1, starts));
            }
        }

        return answer;
    }
};
```

## Complexity

- **Time:** `O(n log n)` — sorting takes `O(n log n)`, followed by one binary
  search per interval.
- **Space:** `O(n)` — the sorted start/index pairs and result each use linear
  space.
