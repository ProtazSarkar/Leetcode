# LeetCode 3010: Divide an Array Into Subarrays With Minimum Cost I

## 📝 Problem Description
You are given an array of integers `nums` of length `n`. The **cost** of an array is defined as its **first element**.

**Goal:** Divide the array into **3 disjoint contiguous subarrays** such that the sum of their costs is minimized.

---

## 💡 Intuition
To minimize the total cost, we need to understand how the subarrays are formed:
1. The **first subarray** must start at index `0`. Therefore, `nums[0]` is **always** included in the total cost.
2. We need to pick two other starting positions for the second and third subarrays. 
3. Since we want the minimum sum, and the cost is simply the first element of each subarray, we just need to find the **two smallest values** in the remainder of the array (`nums[1]` to `nums[n-1]`).

The actual boundaries of the subarrays don't matter as much as their starting elements. As long as we pick the two smallest available numbers after the first element, we can always form valid contiguous subarrays around them.



---

## 🛠️ Approach
1. **Fixed Cost**: The first element `nums[0]` is mandatory.
2. **Search Range**: Look at the subarray starting from index `1` to the end of the array.
3. **Find Two Smallest**: Identify the two smallest integers within this range. 
   - You can do this by sorting the remaining elements or by performing a single pass to find the two minimums.
4. **Calculate Sum**: The result is `nums[0] + smallest + second_smallest`.

---

## 📊 Complexity Analysis
- **Time Complexity**: $O(n)$
  - We only need to traverse the array once (excluding the first element) to find the two smallest values. 
  - *Note: If using sorting, the complexity would be $O(n \log n)$.*
- **Space Complexity**: $O(1)$
  - We only store a few variables to track the minimum values.

---

## 📝 Examples
| nums | Subarrays | Costs | Total Cost |
| :--- | :--- | :--- | :--- |
| `[1, 2, 3, 12]` | `[1], [2], [3, 12]` | `1, 2, 3` | **6** |
| `[5, 4, 3, 2, 1]` | `[5], [4, 3, 2], [1]` | `5, 4, 1` | **10** |
| `[10, 3, 1, 1]` | `[10], [3], [1, 1]` | `10, 3, 1` | **14** |
