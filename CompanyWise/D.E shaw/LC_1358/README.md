# Number of Substrings Containing All Three Characters

## 📝 Problem Description

Given a string `s` consisting only of characters *a*, *b* and *c*.

Return the number of substrings containing **at least** one occurrence of all these characters *a*, *b* and *c*.

### Examples

**Example 1:**
> **Input:** s = "abcabc"  
> **Output:** 10  
> **Explanation:** The substrings containing at least one occurrence of the characters *a*, *b* and *c* are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (the last one starting at index 3).

**Example 2:**
> **Input:** s = "aaabc"  
> **Output:** 3  
> **Explanation:** The substrings containing at least one occurrence of the characters *a*, *b* and *c* are "aaabc", "aabc" and "abc".

### Constraints
* 3 <= s.length <= 5 * 10^4
* `s` only consists of *a*, *b* or *c* characters.

---

## 💡 Intuition & Approach: Sliding Window

A naive brute-force approach checking all substrings would take O(n^2) time, which will result in a Time Limit Exceeded (TLE) error given the constraints. Instead, we can solve this efficiently in linear time using the **Sliding Window (Two-Pointer)** technique.

### How it Works
1. We maintain a window using two pointers: `i` (right boundary) and `j` (left boundary).
2. As we expand the right pointer `i`, we keep a count of 'a', 'b', and 'c'.
3. The moment our window contains at least one of each character (`count_a > 0 && count_b > 0 && count_c > 0`), we know that the current substring from `j` to `i` is valid.
4. **The Key Insight:** If the substring from `j` to `i` is valid, then any substring starting at `j` and ending *beyond* `i` (all the way to the end of the string) is also valid. Therefore, we can instantly add `n - i` to our total count.
5. We then shrink the window from the left by incrementing `j` (and decrementing the respective character count) to see if a smaller window is still valid.