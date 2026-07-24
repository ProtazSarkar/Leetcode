# LeetCode 1877 – Minimize Maximum Pair Sum in Array

## Problem Statement

You are given an integer array `nums` of even length `n`.

You must pair up the elements of `nums` into `n / 2` pairs such that:
- Each element of `nums` is in **exactly one** pair.
- The **maximum pair sum** is **minimized**.

Return the minimized maximum pair sum after optimally pairing up the elements.

---

## Key Observations

- To minimize the maximum sum, you need to "balance" the pairs.
- Pairing the largest number with the second-largest number results in a very high sum.
- To keep the sum as low as possible, the **largest** values should be paired with the **smallest** values.
- This is a **Greedy strategy**: the optimal solution is always found by matching the $i$-th smallest element with the $i$-th largest element.



---

## Approach: Sorting + Two Pointers

### Idea

Since we need to pair the smallest elements with the largest ones, sorting the array is the most efficient first step. Once sorted, we can easily access the smallest and largest elements using two pointers (or a single loop with index math).

### Algorithm

1. **Sort** the input array `nums` in non-decreasing order.
2. Initialize `maxSum` to 0 to track the highest pair sum found.
3. Iterate from `i = 0` to `n / 2 - 1`:
   - Calculate the sum of the $i$-th element (from the start) and the $(n - 1 - i)$-th element (from the end).
   - Compare this sum with `maxSum` and update `maxSum` if the new sum is larger.
4. Return `maxSum`.

---

### Example

Input: `[3, 5, 4, 2, 4, 6]`

- **Sorted Array:** `[2, 3, 4, 4, 5, 6]`
- **Pairs:**
  - `(2, 6)` → sum = 8
  - `(3, 5)` → sum = 8
  - `(4, 4)` → sum = 8
- **Max Pair Sum:** `max(8, 8, 8) = 8`

Output: `8`

---

## Complexity Analysis

| Complexity | Notation | Reason |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n \log n)$ | The sorting step takes $O(n \log n)$. The single traversal takes $O(n)$. |
| **Space Complexity** | $O(1)$ | Aside from the space used by the sorting algorithm, we only use constant extra space. |

---

## Comparison Summary

| Approach | Technique | Time | Space | Suitable |
| :--- | :--- | :--- | :--- | :--- |
| **Brute Force** | Check all possible pairings | $O(n!)$ | $O(n)$ | ❌ |
| **Sorting** | Greedy pairing (Min-Max) | $O(n \log n)$ | $O(1)$ | ✅ |

---

## Final Notes

- Sorting ensures that the largest values are paired with the smallest, which is the mathematical requirement to minimize the maximum sum.
- This approach is highly efficient for large constraints ($n \le 10^5$).
- Always ensure the array length is even as per problem constraints.

Happy coding 🚀
