# Count of Range Sum

## 1. Problem Statement

Given an integer array `nums` and two integers `lower` and `upper`, return the number of range sums that lie in the inclusive range `[lower, upper]`.

A range sum `S(i, j)` is the sum of the elements from index `i` to index `j`, where `i <= j`.

In simple words, count all **continuous subarrays whose sum is between `lower` and `upper`, including both limits**.

### Example

**Input**
```cpp
nums = {-2, 5, -1}
lower = -2
upper = 2
```

**Output**
```text
3
```

**Explanation**

The continuous subarrays with valid sums are:

| Subarray | Sum |
|---|---:|
| `[-2]` | -2 |
| `[-2, 5, -1]` | 2 |
| `[-1]` | -1 |

All three sums lie within `[-2, 2]`. Therefore, the answer is `3`.

---

## 2. Solution Approach 1: Brute Force

### Idea

Generate every possible continuous subarray and calculate its sum.

1. Use an outer loop to select the starting index `i`.
2. Use an inner loop to select the ending index `j`.
3. Maintain a running sum while extending the subarray.
4. If the sum satisfies `lower <= sum <= upper`, increment the answer.
5. Return the total count.

### C++ Code

```cpp
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (sum >= lower && sum <= upper) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

### Complexity Analysis

- **Time Complexity:** `O(n²)` — all possible subarrays are examined.
- **Auxiliary Space Complexity:** `O(1)` — only a few variables are used.

This approach is easy to understand but may be too slow for large inputs.

---

## 3. Solution Approach 2: Prefix Sum + Merge Sort

### Why do we need an optimized approach?

The brute-force solution checks every possible subarray. For an array of size `n`, there are `n(n + 1) / 2` continuous subarrays.

To improve performance, we use **prefix sums and merge sort** to count valid range sums in `O(n log n)` time.

### Step 1: Build the Prefix Sum Array

Create a prefix sum array where:

```text
prefix[0] = 0
prefix[i + 1] = prefix[i] + nums[i]
```

For example:

```text
nums   = [-2, 5, -1]
prefix = [0, -2, 3, 2]
```

The sum of a subarray from index `i` to index `j` can be calculated as:

```text
sum(i, j) = prefix[j + 1] - prefix[i]
```

This allows us to calculate a subarray sum using the difference between two prefix sums.

### Step 2: Convert the Condition

We want every subarray sum to satisfy:

```text
lower <= prefix[j + 1] - prefix[i] <= upper
```

Rearranging the inequality:

```text
prefix[j + 1] - upper <= prefix[i]
prefix[i] <= prefix[j + 1] - lower
```

Therefore, for each ending prefix sum, we need to count the earlier prefix sums that fall within the required interval.

### Step 3: Why Merge Sort?

Checking every pair of prefix sums would still take `O(n²)` time.

Merge sort helps us do better by dividing the prefix sum array into smaller parts and sorting them.

During each merge step:

1. Recursively count valid pairs in the left half.
2. Recursively count valid pairs in the right half.
3. Count valid pairs that cross from the left half to the right half.
4. Merge both halves into sorted order.

Because the two halves are sorted, we can use two pointers to count valid cross-half pairs efficiently.

### Step 4: Count Valid Pairs Using Two Pointers

For a prefix sum `prefix[i]` in the left half, we want prefix sums in the right half that satisfy:

```text
lower <= prefix[j] - prefix[i] <= upper
```

We maintain two pointers:

- `low`: the first position where the difference is at least `lower`.
- `high`: the first position where the difference is greater than `upper`.

The number of valid pairs for the current prefix sum is:

```text
high - low
```

Since both halves are sorted, these pointers can move forward without restarting for each element.

### Step 5: Combine the Results

The total count is:

```text
total count =
    count in left half
  + count in right half
  + count across both halves
```

After counting, merge the two halves into sorted order so that the parent recursive call can process them efficiently.

---

## 4. Optimized C++ Implementation

```cpp
class Solution {
public:
    long long mergeSort(vector<long long>& prefix,
                        int left, int right,
                        long long lower, long long upper) {
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;

        long long count =
            mergeSort(prefix, left, mid, lower, upper) +
            mergeSort(prefix, mid + 1, right, lower, upper);

        int low = mid + 1;
        int high = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (low <= right &&
                   prefix[low] - prefix[i] < lower) {
                low++;
            }

            while (high <= right &&
                   prefix[high] - prefix[i] <= upper) {
                high++;
            }

            count += high - low;
        }

        vector<long long> temp;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (prefix[i] <= prefix[j]) {
                temp.push_back(prefix[i++]);
            } else {
                temp.push_back(prefix[j++]);
            }
        }

        while (i <= mid) {
            temp.push_back(prefix[i++]);
        }

        while (j <= right) {
            temp.push_back(prefix[j++]);
        }

        for (int k = 0; k < (int)temp.size(); k++) {
            prefix[left + k] = temp[k];
        }

        return count;
    }

    long long countRangeSum(vector<int>& nums,
                            int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, n, lower, upper);
    }
};
```

---

## 5. Complexity Comparison

| Approach | Time Complexity | Auxiliary Space |
|---|---|---|
| Brute Force | `O(n²)` | `O(1)` |
| Prefix Sum + Merge Sort | `O(n log n)` | `O(n)` |

The optimized approach uses additional space for the prefix sums and temporary merge arrays.

## 6. Key Takeaways

- A **range sum** is the sum of a continuous subarray.
- **Prefix sums** let us calculate any subarray sum using a difference.
- **Merge sort** divides the problem and keeps the prefix sums sorted.
- **Two pointers** count valid pairs between sorted halves without checking every pair.
- The optimized solution reduces the time complexity from `O(n²)` to `O(n log n)`.

The central insight is that we are not simply sorting an array. We are using the merge sort process to count valid prefix-sum pairs efficiently while preserving the ordering needed for the subarray condition.
