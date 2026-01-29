# LeetCode 2027 – Minimum Moves to Convert String

## 🧩 Problem Description

You are given a string `s` consisting of characters `'X'` and `'O'`.

In one move, you can select **three consecutive characters** of `s` and convert them to `'O'`. Note that if a move is applied to a character that is already `'O'`, it remains `'O'`.

Return the **minimum number of moves** needed so that all the characters of `s` are converted to `'O'`.

---

## 🔍 Key Observations

* **Greedy Choice**: To minimize moves, we should only initiate a move when we encounter an `'X'`.
* **Fixed Window**: Every move covers exactly three characters regardless of whether they are `'X'` or `'O'`.
* **Skip Logic**: Once a move is made starting at index `i`, the characters at `i`, `i+1`, and `i+2` are all accounted for (converted to `'O'`), allowing us to skip ahead to index `i+3`.

---

## 🧠 Approaches

### 1️⃣ Greedy Strategy (Linear Scan)

#### 💡 Idea
The most efficient way to solve this is to traverse the string from left to right. We only care about characters that are currently `'X'`. As soon as we find an `'X'`, we must use a move to cover it. Because a single move can cover three characters, we maximize its impact by letting it cover the current `'X'` and the next two characters.



#### 🛠 Algorithm
1.  Initialize a counter `count = 0`.
2.  Iterate through the string using a pointer `i = 0`.
3.  If `s[i] == 'X'`:
    * Increment `count`.
    * Advance the pointer `i` by 3 (skip the characters covered by this move).
4.  If `s[i] == 'O'`:
    * Simply advance the pointer `i` by 1 to look for the next `'X'`.
5.  Return the final `count`.

---

## ⏱ Complexity Analysis

* **Time Complexity**: $O(n)$ — We perform a single pass through the string of length $n$.
* **Space Complexity**: $O(1)$ — We only use a single integer variable to store the count.
* **Verdict**: ✅ **Optimal**.

---

## 📊 Example Trace

**Input**: `s = "XXOX"`

1.  **Index 0**: Character is `'X'`.
    * `count` becomes 1.
    * Move covers indices 0, 1, and 2.
    * Pointer `i` jumps to 3.
2.  **Index 3**: Character is `'X'`.
    * `count` becomes 2.
    * Move covers indices 3, 4, 5 (out of bounds handled).
    * Pointer `i` jumps to 6.
3.  **End**: Loop terminates.

**Final Result**: 2

---

## Final Notes

* **Greedy Property**: This problem satisfies the greedy choice property because picking the leftmost `'X'` and covering the next two characters never results in a worse solution than any other strategy.
* **Edge Cases**: The algorithm naturally handles cases where the string length is not a multiple of 3 or if the string contains only `'O'`.

Happy coding 🚀
