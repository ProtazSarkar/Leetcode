# LeetCode 3134 – Minimum Removals to Make Array Balanced

## 🧩 Problem Description

Given an integer array `nums` and an integer `k`, an array is considered **balanced** if the value of its maximum element is at most $k$ times the minimum element.

$$\text{max element} \le k \times \text{min element}$$

The goal is to return the **minimum number of elements** to remove so that the remaining array is balanced. Note that an array of size 1 is always balanced.

---

## 🔍 Key Observations

* **Sorting**: Sorting the array allows the minimum element of any contiguous range to be at index $l$ and the maximum at index $r$.
* **Independence**: Minimizing removals is equivalent to finding the **longest** possible subarray that satisfies the balance condition.
* **Condition**: The mathematical check for balance becomes `nums[r] <= (long long)nums[l] * k`.

---

## 🧠 Approaches

### 1️⃣ Brute Force (Recursive)

#### 💡 Idea
This approach uses recursion to explore every possibility by either removing an element from the left or the right side whenever the balance condition is violated.

#### 🛠 Logic Summary
* If the current range $[l, r]$ is not balanced, it branches into two calls: one incrementing the left pointer and one decrementing the right pointer.
* It returns the minimum result of these two paths.

#### ⏱ Complexity
* **Time Complexity**: $O(2^N)$ — Exponential branching leads to redundant calculations and performance issues.
* **Space Complexity**: $O(N)$ — Due to the recursion stack depth.
* **Verdict**: ❌ **TLE (Time Limit Exceeded)**.

---

### 2️⃣ Optimized Approach (Sliding Window)

#### 💡 Idea
Since the array is sorted, a **Sliding Window** (Two Pointers) can find the maximum length of a valid subarray in a single linear pass.



#### 🛠 Logic Summary
* Iterate through the array with a right pointer `r`.
* If the condition `nums[r] > nums[l] * k` is met, shrink the window by moving the left pointer `l` until the condition is satisfied again.
* The final answer is the total size of the array minus the maximum window length found.

#### ⏱ Complexity
* **Time Complexity**: $O(N \log N)$ — Primarily due to sorting; the sliding window traversal itself is $O(N)$.
* **Space Complexity**: $O(1)$ — Only a few variables are used regardless of input size.
* **Verdict**: ✅ **Optimal**.

---

## 📊 Comparison Summary

| Approach | Technique | Time Complexity | Space Complexity | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Brute Force** | Recursion | $O(2^N)$ | $O(N)$ | ❌ TLE |
| **Sliding Window**| Two Pointers | $O(N \log N)$ | $O(1)$ | 🚀 Optimal |

---

## Final Notes

* **Overflow Prevention**: It is critical to cast to `long long` when calculating `nums[l] * k` to avoid 32-bit integer overflow.
* **Efficiency**: The sliding window ensures each element is processed at most twice, making it the most efficient solution for large constraints.

Happy coding 🚀
