# LC 4066 - Maximum Equal Adjacent Pairs After One Replacement

## Problem

Given a 1-indexed integer array `nums`, choose two distinct values `x` and `y` and, at most once, replace every occurrence of `x` with `y`. Return the maximum number of equal adjacent pairs after the operation.

The replacement is global: every occurrence of `x` is changed, not just those in a contiguous part of the array.

## Approach

Count the equal adjacent pairs already present as `base`. These pairs stay equal after any replacement: if both values are `x`, they both become `y`; otherwise they remain unchanged.

For an unequal adjacent pair to become equal, its values must be exactly the two chosen values, in either order. Thus each unequal pair contributes to the frequency of its unordered value pair `{a, b}`. The largest such frequency is the greatest number of new equal pairs one replacement can create.

The answer is:

```text
base + maximum frequency of an unordered unequal adjacent value pair
```

## Algorithm

Scan each adjacent pair `(nums[i], nums[i + 1])`:

1. If both values are equal, increment `base`.
2. Otherwise, normalize the pair as `(min(a, b), max(a, b))`, increment its frequency, and update the maximum frequency.
3. Return `base + maximum frequency`.

The normalization combines both `(x, y)` and `(y, x)` under the same replacement choice.

## Example

For `nums = [2, 8, 2, 5, 5, 6]`:

- The equal pair `(5, 5)` gives `base = 1`.
- The unequal pair `{2, 8}` occurs twice, more than any other unequal pair.
- Replacing `8` with `2` gives `[2, 2, 2, 5, 5, 6]`, with three equal adjacent pairs.

The maximum is `1 + 2 = 3`.

## Correctness

Already-equal pairs remain equal regardless of the replacement, so they contribute `base`. Any unequal pair becomes equal only if it contains the selected two distinct values. Since one operation selects only one unordered value pair, the maximum number of newly equal pairs is the largest frequency of any such pair. The two counts refer to disjoint adjacent pairs, so their sum is achievable and is optimal.

## Complexity

- Time: `O(n log k)`, where `k` is the number of distinct unequal adjacent value pairs (`std::map`).
- Space: `O(k)`.

## Reference

Implementation: [main.cpp](./main.cpp)
