# 2202. Maximize the Topmost Element After K Moves


## 📝 Problem Description

You have a pile of elements (an array `nums`) where `nums[0]` is the top. In exactly `k` moves, you can:
1. **Remove** the top element if the pile isn't empty.
2. **Add** a previously removed element back to the top.

Return the **maximum possible value** of the top element after exactly `k` moves. If the pile must be empty, return `-1`.

---

## 💡 Key Insights & Strategy

The solution relies on a greedy approach, considering what can be at the top after the $k^{th}$ move. There are two primary ways to have a value at the top:

### 1. The Largest of the Removed Elements
If we perform $k-1$ removals, we can use the $k^{th}$ move to put the largest of those $k-1$ elements back on top. 
* We look at all elements from `nums[0]` to `nums[k-2]`.

### 2. The Next Element in the Pile
If we perform $k$ removals, the element that was originally at `nums[k]` will now be at the top.
* Note: This is only possible if $k < n$ (where $n$ is the array size).



### 🚩 Critical Edge Cases
* **$n = 1$:** If there is only one element and $k$ is odd, the pile will always be empty after the moves (remove, add, remove...). Return `-1`.
* **$k = 0$:** No moves are made; the result is simply `nums[0]`.
* **$k > n$:** We can remove all elements and use the remaining moves to toggle the largest element back and forth. The answer will be the maximum element in the entire array.

---

## 📊 Complexity Analysis

| Complexity | Notation | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(\min(n, k))$ | We only iterate through the first $k$ elements of the array. |
| **Space Complexity** | $O(1)$ | While a priority queue can be used, we only actually need the maximum value, which can be tracked with a single variable to achieve constant space. |

---

## 🛠️ Logic Summary
1. Handle the "impossible" case ($n=1, k \text{ is odd}$).
2. Find the maximum value among the first $k-1$ elements.
3. Compare that maximum with the element at index $k$ (if it exists).
4. Return the larger of the two.

---
