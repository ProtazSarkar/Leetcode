# LeetCode 1984 – Minimum Difference Between Highest and Lowest of K Scores

## Problem Statement

You are given a **0-indexed** integer array `nums`, where `nums[i]` represents the score of the $i^{th}$ student. You are also given an integer `k`.

Pick the scores of **any** `k` students from the array so that the difference between the **highest** and the **lowest** of the `k` scores is **minimized**.

Return the minimized difference.

---

## Key Observations

- **Subsets vs. Subarrays:** The problem allows picking *any* $k$ elements (a subset). However, the difference between the maximum and minimum values is minimized when the chosen elements are numerically as close as possible.
- **Sorting is the Catalyst:** In an unsorted array, the $k$ closest elements could be anywhere. Once the array is **sorted**, the $k$ elements that yield the minimum difference will always be **contiguous**.
- **Sliding Window:** After sorting, we only need to compare the first and last elements of every possible window of size $k$.

---

## Approaches

### 1. Brute Force (Recursive Backtracking)

#### Idea
The brute force approach tries to generate every possible subset of size $k$ from the array. For each subset, it calculates the difference between the maximum and minimum values and tracks the overall minimum.

#### Algorithm
1. Use recursion to either **pick** or **skip** the current element.
2. Maintain a count of `picked` elements.
3. Track the `currentMin` and `currentMax` within the recursive path.
4. When `picked == k`, return `currentMax - currentMin`.

#### Complexity
- **Time Complexity:** $O(2^n)$ — Every element has two choices (pick or skip), leading to an exponential number of paths.
- **Space Complexity:** $O(n)$ — Due to the recursion stack depth.

---

### 2. Optimized Approach (Sorting + Sliding Window)

#### Idea
By sorting the array, we transform the problem into finding the smallest "gap" between elements that are $k$ positions apart. This is a classic **Greedy strategy** because the optimal $k$ elements must be adjacent in a sorted list.



#### Algorithm
1. **Sort** the input array `nums` in non-decreasing order.
2. Initialize `minDiff` to `INT_MAX`.
3. Iterate through the array using a pointer `i` from `0` to `n - k`:
   - Let the current window be `nums[i ... i + k - 1]`.
   - The difference for this window is `nums[i + k - 1] - nums[i]`.
   - Update `minDiff` with the smaller value.
4. Return `minDiff`.

#### Complexity
- **Time Complexity:** $O(n \log n)$ — Dominated by the sorting step. The linear scan is $O(n)$.
- **Space Complexity:** $O(1)$ — No extra data structures are used (if sorted in-place).

---

## Example Trace

**Input:** `nums = [9, 4, 1, 7]`, `k = 2`

1. **Sorted Array:** `[1, 4, 7, 9]`
2. **Window 1:** `[1, 4]` → Diff: $4 - 1 = 3$
3. **Window 2:** `[4, 7]` → Diff: $7 - 4 = 3$
4. **Window 3:** `[7, 9]` → Diff: $9 - 7 = 2$
5. **Final Result:** `2`

---

## Comparison Summary

| Approach | Technique | Time | Space | Suitable |
| :--- | :--- | :--- | :--- | :--- |
| **Brute Force** | Recursive Subset Generation | $O(2^n)$ | $O(n)$ | ❌ (Time Limit Exceeded) |
| **Optimized** | Sorting + Sliding Window | $O(n \log n)$ | $O(1)$ | ✅ (Optimal) |

---

## Final Notes

- **Why Brute Force fails:** For $n=1000$, $2^{1000}$ is far beyond the computational limits of any modern computer.
- **Sorting Logic:** Sorting effectively "groups" the closest numbers together, ensuring that the minimum difference can be found by just checking $n-k+1$ windows.

Happy coding 🚀
