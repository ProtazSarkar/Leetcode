# LeetCode 3719. Longest Balanced Subarray I

## 🧩 Problem Description

You are given an integer array `nums`. A subarray is called **balanced** if the number of **distinct even numbers** in the subarray is equal to the number of **distinct odd numbers**.

Return the length of the **longest balanced subarray**.

---

## 🔍 Key Observations

* **Distinct Requirement**: Unlike standard balanced subarray problems, we only count unique numbers. Duplicate even or odd numbers do not increase the respective counts.
* **Subarray Definition**: A subarray is a contiguous part of an array.
* **Parity**: An integer $x$ is even if `x % 2 == 0` and odd if `x % 2 != 0`.

---

## 🧠 Approaches

### 1️⃣ Optimized Brute Force (Rolling Set)

#### 💡 Idea
To find the longest subarray, we can iterate through every possible starting index `i`. For each start, we expand the end index `j` and maintain a running count of distinct even and odd integers.

#### 🛠 Algorithm
1.  Initialize `maxLen = 0`.
2.  Loop `i` from `0` to `n-1` (start of subarray).
3.  For each `i`, initialize a way to track seen numbers (like a Hash Set or a frequency array) and two counters: `distinctEven` and `distinctOdd`.
4.  Loop `j` from `i` to `n-1` (end of subarray):
    * If `nums[j]` has not been seen in the current window:
        * Increment `distinctEven` if `nums[j]` is even, otherwise increment `distinctOdd`.
        * Mark `nums[j]` as seen.
    * If `distinctEven == distinctOdd`, update `maxLen = max(maxLen, j - i + 1)`.
5.  Return `maxLen`.

---

## ⏱ Complexity Analysis

* **Time Complexity**: $O(n^2)$ — We use nested loops to explore subarrays, but update counts incrementally in $O(1)$.
* **Space Complexity**: $O(k)$ — Where $k$ is the number of distinct elements stored in the tracking set.
* **Verdict**: ✅ **Efficient** for medium constraints.

---

## 📊 Example Trace

**Input**: `nums = [1, 2, 1, 2]`

1.  **Start i = 0**:
    * `j = 0` (Val: 1): Odd=1, Even=0.
    * `j = 1` (Val: 2): Odd=1, Even=1. **Balanced!** `maxLen = 2`.
    * `j = 2` (Val: 1): Already seen. Odd=1, Even=1. **Balanced!** `maxLen = 3`.
    * `j = 3` (Val: 2): Already seen. Odd=1, Even=1. **Balanced!** `maxLen = 4`.

**Final Result**: 4
