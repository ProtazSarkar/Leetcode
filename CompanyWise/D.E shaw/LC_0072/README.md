# Edit Distance (LeetCode 72) — Algorithmic Explanation & Notes

This document provides a comprehensive explanation of the Dynamic Programming solution for the **Edit Distance** problem.

---

## 1. Problem Statement
Given two strings `word1` and `word2`, return the **minimum number of operations** required to convert `word1` to `word2`.

You have the following 3 operations permitted on a word:
1. **Insert** a character
2. **Delete** a character
3. **Replace** a character

---

## 2. Core Intuition & Dynamic Programming State

To transform `word1` (of length `m`) into `word2` (of length `n`), we can break it down into subproblems by comparing prefixes of both strings.

### **State Definition**
Let `dp[i][j]` represent the minimum number of operations required to convert the prefix of `word1` of length `i` (`word1[0...i-1]`) into the prefix of `word2` of length `j` (`word2[0...j-1]`).

* **Dimensions of `dp` table:** `(m + 1) x (n + 1)`
* **Target Result:** `dp[m][n]` (converting full `word1` to full `word2`)

---

## 3. Base Cases Initialization

Before filling the table, we handle empty strings:
* **`dp[i][0] = i`**: Converting a prefix of length `i` of `word1` to an empty string requires `i` **deletions**.
* **`dp[0][j] = j`**: Converting an empty string to a prefix of length `j` of `word2` requires `j` **insertions**.

```cpp
for (int i = 0; i <= m; i++) {
    dp[i][0] = i; // Delete all characters from word1
}
for (int i = 0; i <= n; i++) {
    dp[0][i] = i; // Insert all characters into word1
}