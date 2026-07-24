# LeetCode 3030 – Minimize Bitwise Array

## Problem Statement

You are given an array `nums` consisting of `n` prime integers.

Your task is to construct an array `ans` of the same length such that for every index `i`:

ans[i] | (ans[i] + 1) = nums[i]

Among all possible values satisfying the condition, `ans[i]` must be the **minimum possible** value.  
If no such value exists, set `ans[i] = -1`.

---

## Key Observation

- The expression `x | (x + 1)` is **always odd**.
- Therefore, if `nums[i]` is **even**, it is **impossible** to satisfy the condition.
- Since the input consists of **prime numbers**, the only even prime is `2`, which directly results in `-1`.

---

## Approach 1: Brute Force (Baseline)

### Idea

For each number `p = nums[i]`, try all possible values of `x` starting from `0` up to `p - 1` and check whether:

x | (x + 1) == p

The first value of `x` that satisfies the condition is guaranteed to be the **minimum possible**.

If no value satisfies the condition, return `-1`.

### Algorithm

For each element `p` in `nums`:
1. Iterate `x` from `0` to `p - 1`
2. Check if `x | (x + 1) == p`
3. If true, store `x` in `ans[i]` and stop
4. If no such `x` is found, set `ans[i] = -1`

### Example

Input:
nums = [3, 5, 7]

Output:
ans = [1, -1, 3]

Explanation:
- `1 | 2 = 3`
- No value satisfies `x | (x + 1) = 5`
- `3 | 4 = 7`

### Time Complexity

- Worst case per element: `O(p)`
- Overall complexity: `O(n × p)`

### Space Complexity

- `O(1)` extra space (excluding output array)

---

## Approach 2: Optimized Bit Manipulation

### Idea

For an **odd number `p`**, the binary representation ends with one or more trailing `1`s.

To obtain the **minimum valid `x`**, we flip only the **lowest block of trailing `1`s** in `p`.

This ensures:
- `x` is as small as possible
- `x | (x + 1)` reconstructs `p`

### Algorithm

For each number `p`:
1. If `p` is even, return `-1`
2. Initialize:
   - `temp = p`
   - `counter = 1`
3. While the least significant bit of `temp` is `1`:
   - Right shift `temp`
   - Left shift `counter`
4. Right shift `counter` once
5. Compute `x = p ^ counter`
6. Store `x` in the result array

### Example Walkthrough

For `p = 11` (binary `1011`):
- Trailing `1`s count leads to `counter = 2`
- `x = 11 ^ 2 = 9`
- `9 | 10 = 11`

### Time Complexity

- `O(1)` per element
- Overall: `O(n)`

### Space Complexity

- `O(1)` extra space

---

## Files in This Folder

- `brute.cpp` – Brute-force implementation
- `optimal.cpp` – Optimized bit-manipulation solution
- `README.md` – Problem description, approaches, and complexity analysis

---

## Notes

- The brute-force solution is included for clarity and verification.
- The optimized solution is recommended for large inputs.
- This problem is a good demonstration of how binary patterns can eliminate brute force solutions.
