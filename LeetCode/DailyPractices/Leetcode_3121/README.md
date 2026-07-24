# LeetCode 3121 – Count the Number of Special Characters II

## Problem Statement

You are given a string `word`.

A letter `c` is called **special** if:
1. It appears in both lowercase and uppercase forms in the string.
2. Every lowercase occurrence of `c` appears **before** the first uppercase occurrence of `c`.

Return the number of special letters in `word`.

---

## Key Observation

For a character to be special:

- The character must exist in:
  - lowercase (`a-z`)
  - uppercase (`A-Z`)
- The **last lowercase occurrence** must appear before the **first uppercase occurrence**.

So for every character:
- Store:
  - the **last index** of lowercase occurrence
  - the **first index** of uppercase occurrence

Condition:

```cpp
lastLowercase < firstUppercase
```

---

## Approach: Index Tracking

### Idea

We maintain two arrays:

- `lowers[26]`
  - Stores the **last occurrence** of each lowercase character
- `uppers[26]`
  - Stores the **first occurrence** of each uppercase character

Then for every letter:
- If both lowercase and uppercase exist
- And:

```cpp
lowers[i] < uppers[i]
```

Then that character is special.

---

## Algorithm

1. Initialize:
   - `lowers` with `-1`
   - `uppers` with `INF`
2. Traverse the string:
   - If lowercase:
     - update last occurrence
   - If uppercase:
     - update first occurrence
3. Iterate through all 26 letters:
   - Check whether:
     - lowercase exists
     - uppercase exists
     - lowercase index < uppercase index
4. Count valid characters

---

## Example Walkthrough

### Example 1

Input:

```txt
word = "aaAbcBC"
```

Tracking:
- `a`
  - last lowercase = 1
  - first uppercase = 2
  - valid → special
- `b`
  - lowercase at 3
  - uppercase at 5
  - valid → special
- `c`
  - lowercase at 4
  - uppercase at 6
  - valid → special

Output:

```txt
3
```

---

### Example 2

Input:

```txt
word = "AbBCab"
```

Tracking:
- `a`
  - lowercase occurs after uppercase
  - invalid
- `b`
  - lowercase occurs after uppercase
  - invalid

Output:

```txt
0
```

---

## Time Complexity

### Traversing the string
- `O(n)`

### Checking all characters
- `O(26)` ≈ `O(1)`

### Overall Complexity

```txt
O(n)
```

---

## Space Complexity

Two arrays of size `26`:

```txt
O(1)
```

---

## Files in This Folder

- `solution.cpp` – Main optimized solution
- `README.md` – Explanation, intuition, and complexity analysis

---

## Notes

- The problem becomes simple once we track:
  - last lowercase position
  - first uppercase position
- Using fixed-size arrays makes the solution highly efficient.
- This is a clean example of:
  - character indexing
  - frequency/position tracking
  - greedy validation using indices.