# Q2. Minimum Rotations to Dial a Number II

**Difficulty:** Medium

## Problem

The dial contains the digits `0` through `9` in circular order, so `0` and `9` are adjacent. The pointer starts at `0`. Given a digit string `s`, dial its digits from left to right using the fewest rotations; each move rotates the pointer by one position in either direction.

Before dialing, you may choose at most one index `k` and reverse the suffix `s[k..n-1]`. Find the minimum number of rotations over all choices, including making no change.

## Approach

The cost of moving between two digits is their shorter distance around the ten-position circle:

```text
distance(a, b) = min(|a - b|, 10 - |a - b|)
```

For any fixed string, the total cost is the sum of:

1. Moving from `0` to the first digit.
2. Moving between each pair of consecutive digits.

If the suffix starting at `k` is reversed:

- The prefix before `k` remains unchanged. Its cost is `prefix[k]`, where `prefix[i]` is the cost of dialing `s[0..i-1]` in its original order.
- The next digit after that prefix is the original last digit, `s[n-1]`. The transition into the reversed suffix therefore costs `distance(s[k-1], s[n-1])`, or `distance(0, s[n-1])` when `k == 0`.
- The reversed suffix is dialed from `s[n-1]` down to `s[k]`. Its internal transition cost is `backward[k]`, precomputed as the sum of distances between adjacent digits from right to left.

Thus, for each possible `k`:

```text
cost(k) = prefix[k]
        + distance(k == 0 ? 0 : s[k-1], s[n-1])
        + backward[k]
```

Initialize the answer with the cost of dialing the original string, which represents choosing not to reverse anything. Then evaluate the formula for every suffix start.

## Example

```text
s = "909"
```

Without a reversal, the pointer moves `0 -> 9 -> 0 -> 9`, for a total cost of `1 + 1 + 1 = 3`.

Reverse the suffix starting at index `1`: `"909"` becomes `"990"`. The pointer moves `0 -> 9 -> 9 -> 0`, for a total cost of `1 + 0 + 1 = 2`. The minimum is `2`.

## Correctness

For a chosen suffix start `k`, reversing the suffix leaves every digit before `k` in its original position and order, so its dialing cost is exactly `prefix[k]`. The first digit of the reversed suffix is the original final digit, so the transition from the unchanged prefix (or from the initial pointer when `k = 0`) is exactly the boundary distance in the formula. The remaining digits are visited in the order `s[n-1], s[n-2], ..., s[k]`; their consecutive transition costs are exactly `backward[k]`.

Therefore, `cost(k)` equals the total rotations after reversing at `k`. Every allowed reversal has exactly one such starting index, and the unchanged string is included in the initial answer. Taking the minimum over all these candidates consequently returns the optimal number of rotations.

## Complexity

- **Time:** `O(n)` to build the prefix and reverse-direction costs and evaluate all suffix starts.
- **Space:** `O(n)` for the digit, prefix-cost, and backward-cost arrays.
