# 3713. Longest Balanced Substring I
[View on LeetCode](https://leetcode.com/problems/longest-balanced-substring-i/)

## 🧩 Problem Description

Given a string `s` consisting of lowercase English letters, find the length of the **longest balanced substring**. 

A substring is called **balanced** if all **distinct** characters present in that substring appear the exact **same number of times**.

---

## 🔍 Key Observations

* **Character Presence**: Only characters actually found within the substring are considered. If a character does not appear, it does not affect the balance.
* **Alphabet Constraint**: With only 26 possible lowercase letters, frequency tracking is bounded by a constant size.
* **Search Efficiency**: Once a balanced substring of a certain length is found, smaller or equal lengths starting from the same index can be ignored.

---

## 🧠 Approaches

### 1️⃣ Brute Force

#### 💡 Idea
Manually check every possible substring by iterating through all start and end points and calculating character frequencies from scratch for each.

#### 🛠️ Technique
1.  Use two nested loops to define every substring $[i, j]$.
2.  Use a hash map or an array of size 26 to count occurrences of each character.
3.  Check if all values in the frequency map are equal.

#### ⏱️ Complexity
* **Time Complexity**: $O(N^3)$ — Total substrings $O(N^2)$ multiplied by $O(N)$ for counting.
* **Space Complexity**: $O(1)$ — Only requires a fixed-size frequency array.
* **Verdict**: ❌ **TLE (Time Limit Exceeded)** for larger constraints.

---

### 2️⃣ Segment Tree Optimization

#### 💡 Idea
Optimize range frequency counting by using a **Segment Tree**. Each node in the tree stores a frequency array for its specific range, allowing for logarithmic query times.

#### 🛠️ Technique
1.  **Build**: Recursively construct a tree where each node aggregates the character counts of its children.
2.  **Query**: Retrieve the frequency array for any range $[qL, qR]$ by combining $O(\log N)$ tree nodes.
3.  **Validation**: Check the resulting 26-length array for uniform non-zero frequencies.

#### ⏱️ Complexity
* **Time Complexity**: $O(N^2 \log N)$ — Improved by pruning and searching from the longest lengths first.
* **Space Complexity**: $O(N)$ — Specifically $O(4N \times 26)$ to store the tree nodes.
* **Verdict**: ✅ **Passes** with proper pruning logic.

---

### 3️⃣ Prefix Sum (Optimal)

#### 💡 Idea
Precompute character counts using a **2D Prefix Sum array**. This allows the frequency of any character in any range to be calculated in constant time.

#### 🛠️ Technique
1.  Construct a 2D array `pref[N+1][26]` where `pref[i][char]` stores the count of that character from the start up to index `i-1`.
2.  Calculate any range frequency using the formula: $count = pref[end+1] - pref[start]$.
3.  Verify the balance across the 26 possible characters in $O(26)$ per substring.

#### ⏱️ Complexity
* **Time Complexity**: $O(26 \cdot N^2)$.
* **Space Complexity**: $O(26 \cdot N)$.
* **Verdict**: 🚀 **Optimal** approach for this constraint.

---

## 📊 Comparison Summary

| Approach | Technique | Time Complexity | Space Complexity | Suitable |
| :--- | :--- | :--- | :--- | :--- |
| **Brute Force** | Nested Loops | $O(N^3)$ | $O(1)$ | ❌ TLE |
| **Segment Tree** | Range Query | $O(N^2 \log N)$ | $O(N)$ | ✅ Passes |
| **Prefix Sum** | 2D Precomputation| $O(N^2)$ | $O(N)$ | 🚀 Optimal |

---

## 💡 Pruning & Optimization Tips

* **Reverse Search**: Start the inner loop from the end of the string ($j = N-1$ down to $i$). The first balanced substring found will be the longest for that starting position.
* **Remaining Length Check**: If the distance from the current starting index to the end of the string is less than the `maxLen` already found, terminate the search early.
* **Window Pruning**: If the current substring length $(j - i + 1)$ is already smaller than or equal to `maxLen`, break the inner loop immediately.

Happy coding 🚀
