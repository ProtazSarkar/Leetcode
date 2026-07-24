# LeetCode 744: Find Smallest Letter Greater Than Target

## 📝 Problem Description
You are given an array of characters `letters` that is sorted in **non-decreasing order**, and a character `target`. There are at least two different characters in `letters`.

**Goal:** Return the smallest character in `letters` that is **lexicographically greater** than `target`. If such a character does not exist, return the first character in `letters` (the "wrap-around" case).

---

## 💡 Intuition
Since the array is already **sorted**, we can skip the linear scan and use **Binary Search**. The goal is to find the "Upper Bound"—the first position where a character is strictly greater than our target. 

If our search index ends up being equal to the length of the array, it means every character was less than or equal to the target. In that case, we "wrap around" to the start of the array.



---

## 🛠️ Approach
1. **Binary Search Initialization**: Set `low = 0` and `high = n - 1`.
2. **Strict Comparison**: During the search, even if `letters[mid] == target`, we must move the `low` pointer to `mid + 1` because we need a character that is **strictly greater**.
3. **The Wrap-Around Logic**: After the loop finishes, `low` will point to the correct character. By returning `letters[low % n]`, we automatically handle cases where `low` reaches the end of the array, redirecting it back to index `0`.

---

## 📊 Complexity Analysis

* **Time Complexity**: $O(\log n)$
  * Because we use binary search, the search space is divided by two in every iteration.
* **Space Complexity**: $O(1)$
  * We use a fixed amount of extra space regardless of the input size (only three integer pointers).

---

## 📝 Examples
| letters | target | Output | Explanation |
| :--- | :--- | :--- | :--- |
| `["c", "f", "j"]` | `"a"` | `"c"` | 'c' is the smallest char > 'a' |
| `["c", "f", "j"]` | `"c"` | `"f"` | 'f' is the smallest char > 'c' |
| `["x", "x", "y", "y"]` | `"z"` | `"x"` | No char > 'z', wrap around to index 0 |
