# LeetCode 1653 – Minimum Deletions to Make String Balanced

## 🧩 Problem Description

You are given a string `s` consisting only of characters 'a' and 'b'. A string is considered **balanced** if there is no pair of indices $(i, j)$ such that $i < j$, $s[i] = 'b'$, and $s[j] = 'a'$.

In simpler terms, all 'a's must appear before all 'b's. The goal is to return the **minimum number of deletions** needed to achieve this balance.

---

## 🔍 Key Observations

* **Conflict Trigger**: Balance is only broken when an 'a' appears after a 'b'.
* **Decision Point**: Every time we encounter a misplaced 'a' (one that follows a 'b'), we must choose:
    1.  Delete the current 'a'.
    2.  Keep the current 'a' and delete all preceding 'b's.
* **Grouping**: The problem can be viewed in terms of "blocks" of consecutive identical characters (e.g., `"aaabbba"` as 3 'a's, 3 'b's, 1 'a').

---

## 🧠 Approaches

### 1️⃣ Brute Force (Recursive)

#### 💡 Idea
Explore every possible state by either keeping or deleting the current character.

#### 🛠 Logic Summary
* If the string is not balanced, branch into two recursive calls: one where the character at index `i` is removed and one where it is kept.
* Use a helper function to verify if the resulting string is balanced (no 'b' before an 'a').
* **Verdict**: ❌ **TLE (Time Limit Exceeded)** due to $O(2^N)$ branching.

### 2️⃣ "Next Level" Brute Force (Block-Based)

#### 💡 Idea
Instead of individual characters, process consecutive blocks of 'a's and 'b's to reduce the number of decisions.

#### 🛠 Logic Summary
* Group the string into `pair<int, char>` blocks (e.g., `{count, type}`).
* Recurse through blocks: If an 'a' block follows a 'b' block, decide whether to delete the whole 'a' block or delete all previous 'b' blocks.
* **Verdict**: ❌ **Efficiency Issues** without memoization, though faster than character-level recursion.

### 3️⃣ Optimized Approach (Bottom-Up DP)

#### 💡 Idea
Convert the recursive decision logic into a linear iterative process. We track the "best" result found so far as we scan the string once.


#### 🛠 Logic Summary
* Maintain a running count of 'b' characters encountered.
* Maintain a variable `res` to store the minimum deletions for the prefix processed so far.
* **When you see a 'b'**: Increment the `b_count`.
* **When you see an 'a'**: Update `res = min(res + 1, b_count)`.
    * `res + 1` represents deleting the current 'a'.
    * `b_count` represents keeping this 'a' and deleting all 'b's seen so far.
* **Verdict**: ✅ **Optimal**.

---

## 📊 Comparison Summary

| Approach | Technique | Time Complexity | Space Complexity | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Brute Force** | Pure Recursion | $O(2^N \cdot N)$ | $O(N)$ | ❌ TLE |
| **Block Recursion** | Grouped Brute Force | $O(2^M)$ | $O(M)$ | ❌ Slow |
| **Bottom-Up DP** | Tabulation / Greedy | $O(N)$ | $O(1)$ | 🚀 Optimal |

---

## Final Notes

* **Direction**: While the problem can be solved by looking at the string from left to right, the same logic applies in reverse.
* **Space Optimization**: By using a single variable to track deletions (`res`) and another for `b_count`, we avoid the need for an $O(N)$ DP array.

Happy coding 🚀
