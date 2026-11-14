# LeetCode 3240 – Count Non-Decreasing Subarrays After K Operations

## Problem Statement

You are given an array `nums` of `n` integers and an integer `k`.

For each subarray of `nums`, you can apply up to `k` operations on it. In each operation, you can increment any element of the subarray by 1.

A subarray is considered valid if, after at most `k` increments, it becomes non-decreasing.

Return the number of subarrays that can be made non-decreasing after performing at most `k` operations.

---

## Key Idea

For a subarray to become non-decreasing, every element must be at least as large as the previous one.

If a subarray has a descending pair such as:

```txt
nums[i] > nums[i+1]
```

then we need to increase some values to fix that drop.

The total cost needed to fix a subarray is the sum of all required increments. We only count subarrays whose required cost is at most `k`.

---

## Observation

This is a sliding-window problem with a cost metric.

For each starting index `i`, we try to expand the window to the right while the required cost stays within `k`.

The important part is that the cost can be updated efficiently using a monotonic structure.

---

## Efficient Approach

### 1. Traverse from right to left

We process every possible left boundary `i` from the end to the beginning.

### 2. Maintain a deque of candidate indices

A deque keeps indices in a structure that helps us track where the array is decreasing.

When we see a value larger than the previous one, we can convert the cost contribution of the affected segment into a form that is easy to maintain.

### 3. Maintain total required cost

`cost` stores the total increment needed for the current valid window.

If `cost > k`, we shrink the right boundary until the cost fits again.

### 4. Count valid subarrays

For each left index `i`, the number of valid windows starting at `i` is:

```txt
j - i + 1
```

where `j` is the current rightmost valid boundary.

---

## Why This Works

The key invariant is:

- `cost` always represents the minimum total increment required to make the current window non-decreasing.
- When `cost <= k`, all subarrays ending at the current right boundary are valid.
- When `cost > k`, we move the right boundary left until the condition is restored.

This lets us count all valid subarrays in linear time.

---

## Complexity

### Time Complexity

```txt
O(n)
```

Each index is added and removed from the deque at most once.

### Space Complexity

```txt
O(n)
```

The deque and auxiliary arrays are linear in size.

---

## Example

```txt
nums = [1, 3, 2, 5, 4]
k = 1
```

Some subarrays can be fixed with just a few increments, while others require more than `k` operations.

The algorithm counts exactly those subarrays whose total required increment is at most `1`.

---

## C++ Solution

See:

- `soln.cpp` — optimized accepted solution
- `approach.cpp` — alternate approach draft

---

## Notes

This problem is a classic example of combining:

- monotonic queue/deque techniques
- sliding window logic
- cost-based prefix maintenance

The implementation is efficient enough for large input sizes while keeping the logic clean and easy to reason about.
