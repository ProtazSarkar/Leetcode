# Partition Array into Disjoint Intervals

**LeetCode 915**

## Problem Statement

Given an integer array `nums`, split it into two non-empty contiguous parts,
`left` and `right`, so that:

```text
max(left) <= min(right)
```

Return the smallest possible length of `left`.

### Example

```text
Input:  nums = [5, 0, 3, 8, 6]
Output: 3
```

The split after index `2` gives `left = [5, 0, 3]` and `right = [8, 6]`.
The maximum of `left` is `5`, which is no greater than the minimum of `right`,
which is `6`.

## Approach: Track the Left Maximum

Scan the array from left to right while tracking:

- `left_max`: the maximum value in the current candidate left partition.
- `curr_max`: the maximum value seen in the entire prefix scanned so far.
- `ans`: the length of the left partition at the most recent required boundary.

If the current value is less than `left_max`, it cannot be placed in the right
partition: doing so would make `min(right)` smaller than `max(left)`. Extend
the left partition through the current index by setting `ans = i + 1`, and
update `left_max` to `curr_max`. Otherwise, the current value can remain in
the right partition without breaking the condition.

The final `ans` is the smallest valid left-partition length.

## C++ Implementation

```cpp
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int left_max = nums[0];
        int curr_max = nums[0];
        int ans = 1;

        for (int i = 1; i < nums.size(); i++) {
            curr_max = max(curr_max, nums[i]);

            if (nums[i] < left_max) {
                left_max = curr_max;
                ans = i + 1;
            }
        }

        return ans;
    }
};
```

## Complexity

- **Time:** `O(n)` — the array is scanned once.
- **Space:** `O(1)` — only a few variables are used.
