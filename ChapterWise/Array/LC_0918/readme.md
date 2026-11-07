# Maximum Sum Circular Subarray

**LeetCode 918**

## Problem Statement

Given a circular integer array `nums`, return the largest possible sum of a
non-empty subarray. In a circular array, the element after the last element is
the first element. A subarray can wrap from the end to the beginning, but it
cannot include any array element more than once.

### Example

```text
Input:  nums = [1, -2, 3, -2]
Output: 3
```

The maximum-sum subarray is `[3]`, with sum `3`.

## Approach: Kadane's Algorithm and the Minimum Subarray

There are two possibilities for a maximum-sum subarray:

1. **It does not wrap around.** Find it with the standard maximum-subarray
   version of Kadane's algorithm.
2. **It wraps around.** It consists of a suffix and a prefix. The elements it
   leaves out form one contiguous subarray in the middle. Therefore:

   ```text
   wrapped maximum = total array sum - minimum subarray sum
   ```

In one pass, the solution tracks the total sum, the maximum subarray sum, and
the minimum subarray sum. For each value `x`, the running sums are updated as:

```text
current maximum = max(x, current maximum + x)
current minimum = min(x, current minimum + x)
```

If every value is negative, `total sum - minimum subarray sum` would be zero,
representing an invalid empty subarray. In this case, return the maximum
element (the least negative subarray sum). Otherwise, return the larger of
the non-wrapping and wrapping results.

## C++ Implementation

```cpp
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        int curr_max = 0;
        int curr_min = 0;
        int max_sum = nums[0];
        int min_sum = nums[0];

        for (int x : nums) {
            total_sum += x;

            curr_max = max(x, curr_max + x);
            max_sum = max(max_sum, curr_max);

            curr_min = min(x, curr_min + x);
            min_sum = min(min_sum, curr_min);
        }

        if (max_sum < 0) {
            return max_sum;
        }

        return max(max_sum, total_sum - min_sum);
    }
};
```

## Complexity

- **Time:** `O(n)` — the array is processed once.
- **Space:** `O(1)` — only a fixed number of scalar variables are used.
