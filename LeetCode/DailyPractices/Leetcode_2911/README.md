# LeetCode 2911 – Minimum Changes to Make K Semi-palindromes

## Problem

Partition `s` into exactly `k` non-empty, contiguous substrings. Change as few letters as possible so every substring is a semi-palindrome, and return the minimum number of changes.

A substring of length `m` is a semi-palindrome if there is a divisor `d` of `m` with `1 <= d < m` such that, for every offset from `0` to `d - 1`, the characters at indices
`offset, offset + d, offset + 2d, ...` form a palindrome.

## Approach

The solution combines two ideas:

1. **Find the cost of making a substring semi-palindromic.** For each valid divisor `d` of its length, split the substring into the `d` residue-class groups. Each group can be made into a palindrome by changing one character for every mismatched mirrored pair. The minimum total over all divisors is the substring's cost.
2. **Partition with memoized recursion.** `solve(start, partsLeft)` returns the minimum cost to partition the suffix beginning at `start` into exactly `partsLeft` semi-palindromes. Try each possible end for the next part, add its semi-palindrome cost, and recurse on the remaining suffix.

Every part must contain at least two characters because a length-one string has no valid divisor. The recursion checks that enough characters remain and only considers endpoints that leave at least two characters for every later part.

## Correctness intuition

For any chosen substring, checking every proper divisor considers every permitted repeating pattern. Within a group, each mirrored pair is independent, and one change is sufficient and necessary when the pair differs. Thus the minimum over divisors is the minimum number of changes for that substring.

For the partition, every valid solution has some first substring ending at one of the tested positions. The recurrence considers each such choice and combines its cost with the optimal partition of the remaining suffix. Memoization ensures each `(start, partsLeft)` state is solved only once.

## Complexity

Let `n` be the length of `s`, and let `τ(m)` denote the number of divisors of `m`. Computing a semi-palindrome cost for a substring of length `m` takes `O(m * τ(m))` time: each divisor processes the substring's characters once. Define `T(n) = max(τ(m))` for `2 <= m <= n`.

In the current implementation, substring costs are recomputed while exploring DP transitions:

- **Time:** `O(k * n^3 * T(n))` as a conservative upper bound.
- **Space:** `O(n * k + n)` for the memo table and temporary substring/group data, plus `O(k)` recursion depth.

## Example

For `"abcabc"`, choose `d = 3`. Its groups are `"aa"`, `"bb"`, and `"cc"`; all are palindromes, so the substring needs `0` changes.
