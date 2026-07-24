# LeetCode 761 – Special Binary String

## 🧩 Problem Description

You are given a **special binary string** `s`.

A binary string is considered **special** if:

1. The number of `'1'`s is equal to the number of `'0'`s.
2. For every prefix of the string, the number of `'1'`s is **greater than or equal to** the number of `'0'`s.

A move consists of choosing **two consecutive, non-empty, special substrings** and swapping them.

Your goal is to return the **lexicographically largest** string possible after performing any number of such moves.

---

## 🔍 Key Observations

- **Balanced Structure**: A special binary string behaves exactly like valid parentheses.  
  - `'1'` → `'('`  
  - `'0'` → `')'`

- **Prefix Guarantee**: The balance (count of 1 − count of 0) never goes negative.

- **Decomposition Property**:  
  Every special string has structure:

  ```
  1 + (special string) + 0
  ```

- **Swap Freedom**:  
  Since we can swap consecutive special substrings, we can rearrange **sibling blocks** freely.

- **Lexicographical Goal**:  
  To maximize lexicographically → place larger blocks first.

---

## 🧠 Approaches

### 1️⃣ Brute Force (Swap Simulation)

#### 💡 Idea
Try all possible valid swaps between consecutive special substrings and track the maximum lexicographic result.

#### 🛠 Logic Summary
- Identify all possible special substrings.
- Try swapping all valid consecutive pairs.
- Recursively explore resulting configurations.

#### ❌ Verdict
- Explodes combinatorially.
- Time complexity becomes exponential.
- Not feasible for large inputs.

---

### 2️⃣ Recursive Divide & Sort (Greedy + Recursion)

#### 💡 Core Idea

Instead of trying swaps manually:

1. Split the string into **top-level special substrings** using a balance counter.
2. Recursively solve each substring’s inner portion.
3. Sort those substrings in **descending lexicographical order**.
4. Join them back together.

---

#### 🛠 Logic Summary

- Maintain a counter:
  - `+1` for `'1'`
  - `-1` for `'0'`
- Whenever counter becomes `0`, we found one complete special block.
- For each block:
  - Remove outer `'1'` and `'0'`
  - Recursively solve inside
  - Rebuild block
- Sort all blocks in descending order.
- Concatenate and return.

---

#### ✨ Why Sorting Works

Because:

- Only consecutive special substrings can be swapped.
- Splitting guarantees they are consecutive.
- To maximize lexicographically:
  - Put larger blocks first.
  - Sorting achieves this optimally.

---

## 📊 Complexity Analysis

| Approach | Technique | Time Complexity | Space Complexity | Status |
|-----------|------------|-----------------|-----------------|--------|
| **Swap Simulation** | Backtracking | Exponential | High | ❌ TLE |
| **Recursive Sort** | Greedy + Recursion | O(N²) | O(N) | 🚀 Optimal |

---

## 🌳 Structural Insight

The string forms a **tree-like structure**:

- Each special substring is a node.
- Nested substrings are children.
- At every node:
  - Recursively solve children.
  - Sort children.
  - Reconstruct.

This guarantees the lexicographically largest arrangement.

---

## 🏁 Final Notes

- The input is guaranteed to be special.
- The solution relies on:
  - Prefix balance property
  - Recursive decomposition
  - Greedy sorting
- No dynamic programming table is required.

Happy coding 🚀