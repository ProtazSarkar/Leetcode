# K-th Smallest Prime Fraction

**LeetCode 786**

## Problem Statement

You are given an integer array `arr` sorted in non-decreasing order, where each element is a positive integer. Consider all fractions `arr[i] / arr[j]` where `0 <= i < j < arr.length`. Return the numerator and denominator of the `k`-th smallest fraction in sorted order, where the fraction is represented as an array `[numerator, denominator]`.

### Example

```text
Input: arr = [1,2,3,5], k = 3
Output: [2,5]
```

## Approach

The key observation is that every possible fraction lies in the range `[0, 1]`, so we can binary-search the answer value. For a guessed mid-value, we count how many fractions are `<= mid` using a two-pointer scan.

For each index `i`, we find the first index `j` such that `arr[i] / arr[j] <= mid`. Then every denominator from `j` to `n - 1` is valid, giving a contribution of `n - j` to the total count.

We also track the largest valid fraction encountered for the current threshold. When the count reaches `k`, we have the required fraction.

To avoid floating-point precision issues, we run the binary search for a fixed number of iterations (for example, 60), which gives a highly accurate result in practice.

## Complexity

- Time: `O(n log precision)`
- Space: `O(1)`

The solution uses binary search over the fraction value combined with a linear two-pointer counting step.