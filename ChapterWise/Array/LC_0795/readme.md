# 795. Number of Subarrays with Bounded Maximum

## Problem Statement

Given an integer array `nums` and two integers `left` and `right`, return the number of contiguous, non-empty subarrays such that the maximum element of each subarray lies within the range `[left, right]`.

In other words, for every valid subarray:

`left <= maximum element <= right`

## Example

**Input**
```cpp
nums = [2, 1, 4, 3], left = 2, right = 3
```

**Output**
```text
3
```

**Explanation**

The valid subarrays are:

- `[2]` — maximum is 2.
- `[2, 1]` — maximum is 2.
- `[3]` — maximum is 3.

Therefore, the answer is `3`.

---

## Approach: One-Pass Counting

Instead of generating every possible subarray and calculating its maximum, we can solve the problem in a single traversal using two indices.

### Key Observation

Every element belongs to one of three categories:

1. **`nums[i] > right`**: The element cannot belong to any valid subarray containing it because the maximum would exceed `right`.
2. **`nums[i] < left`**: The element can belong to a valid subarray, but it cannot independently make the maximum reach `left`.
3. **`left <= nums[i] <= right`**: The element can serve as the maximum of a valid subarray.

We maintain two variables:

- `lastInvalid`: The most recent index where `nums[i] > right`.
- `lastValid`: The most recent index where `nums[i] >= left`.

Initially, both are set to `-1`.

### How Does Counting Work?

Suppose we are currently at index `i`.

First, update `lastInvalid` if the current element exceeds `right`.

Next, update `lastValid` if the current element is at least `left`.

The number of valid subarrays ending at index `i` is:

```cpp
lastValid - lastInvalid
```

**Why?**

A valid subarray ending at `i` must satisfy two conditions:

- Its starting index must be after `lastInvalid`, so it does not contain an element greater than `right`.
- Its starting index must be at or before `lastValid`, so the subarray contains at least one element greater than or equal to `left`.

Therefore, the possible starting indices range from `lastInvalid + 1` to `lastValid`, giving:

`lastValid - lastInvalid` valid subarrays.

If `lastValid <= lastInvalid`, the result is zero, because no valid starting position exists.

Add this count to the answer at every index.

---

## C++ Solution

```cpp
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int lastInvalid = -1;
        int lastValid = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > right) {
                lastInvalid = i;
            }

            if (nums[i] >= left) {
                lastValid = i;
            }

            ans += max(0, lastValid - lastInvalid);
        }

        return ans;
    }
};
```

---

## Dry Run

Consider:

```text
nums = [2, 1, 4, 3]
left = 2
right = 3
```

| Index `i` | `nums[i]` | `lastInvalid` | `lastValid` | New subarrays | Total |
|---:|---:|---:|---:|---:|---:|
| 0 | 2 | -1 | 0 | 1 | 1 |
| 1 | 1 | -1 | 0 | 1 | 2 |
| 2 | 4 | 2 | 0 | -2 | 0 |
| 3 | 3 | 2 | 3 | 1 | 1 |

The table illustrates an important implementation detail: **the raw difference can be negative** when the most recent invalid index is ahead of the most recent valid index. In that situation, the contribution must be zero.

The correct update is therefore:

```cpp
ans += max(0, lastValid - lastInvalid);
```

With this correction, the contributions are `1, 1, 0, 1`, producing the answer `3`.

---

## Corrected C++ Implementation

```cpp
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums,
                              int left, int right) {
        int ans = 0;
        int lastInvalid = -1;
        int lastValid = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > right) {
                lastInvalid = i;
            }

            if (nums[i] >= left) {
                lastValid = i;
            }

            ans += max(0, lastValid - lastInvalid);
        }

        return ans;
    }
};
```

## Complexity Analysis

Let `n` be the length of `nums`.

- **Time Complexity:** `O(n)` — each element is processed once.
- **Space Complexity:** `O(1)` — only a constant number of variables are used.

## Why Not a Segment Tree?

A segment tree can help answer range-maximum queries, but this problem does not require querying the maximum of each individual subarray. By tracking the latest invalid and valid positions, we count all valid subarrays in one pass.

## Key Takeaway

When a problem asks you to count subarrays satisfying a condition on their maximum, look for ways to count valid subarrays ending at each index rather than explicitly generating every subarray.

This technique avoids the brute-force `O(n²)` approach and achieves `O(n)` time with constant extra space.