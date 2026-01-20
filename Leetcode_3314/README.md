# LeetCode 3030 – Minimize Bitwise Array

## Problem Statement
You are given an array `nums` consisting of `n` prime integers.

Construct an array `ans` of length `n` such that for each index `i`:

ans[i] OR (ans[i] + 1) = nums[i]

Additionally, each value `ans[i]` should be **minimum possible**.

If no such value exists for a given index, set `ans[i] = -1`.

---

## Approach (Brute Force)

For each element `p = nums[i]`:
1. Try all values of `x` from `0` to `p - 1`
2. Check whether:
{{x | (x + 1) == p}}
3. The first value that satisfies the condition is the minimum possible `x`
4. If no value satisfies the condition, return `-1`

---

## Example

Input:
nums = [3, 5, 7]

Output:
ans = [1, -1, 3]

Explanation:
- `1 | 2 = 3`
- No value satisfies `x | (x + 1) = 5`
- `3 | 4 = 7`

---

## Time Complexity
- Worst case per element: `O(p)`
- Overall complexity: **O(n × p)**

---

## Space Complexity
- **O(1)** extra space (excluding output array)

---

## Notes
- This is a brute-force solution intended for clarity and correctness.
- A more optimized bit-manipulation solution exists that runs in `O(n)` time.
- Separate files can be used to store brute-force and optimal solutions.

---

## Files in This Folder
- `brute.cpp` – Brute force implementation
- `README.md` – Problem explanation and complexity analysis

