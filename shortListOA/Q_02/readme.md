# Question 2: Constructing Non-Decreasing Arrays with Digit Sum Constraints

## Problem Description

Given an array of $n$ integers called `required_sums`, there is another array of $n$ integers called `result` that can be constructed to meet the following conditions:
* The values are non-decreasing, i.e., $\text{result}[i] \ge \text{result}[i - 1]$ ($1 < i \le n$).
* The sum of digits of $\text{result}[i] = \text{required\_sums}[i]$ for every $1 \le i \le n$.
* $\text{result}[i] \le 5000$, for every $1 \le i \le n$.

Find the number of distinct ways that `result` can be constructed to satisfy the constraints. Since the answer can be large, compute it modulo ($10^9 + 7$).

> **Note:** Two arrays $a$ and $b$ of length $n$ are distinct if $a[i]$ is not equal to $b[i]$ for at least one $i$ in $1 \le i \le n$.

### Solution Approach
The key observation is that each position depends only on the previous chosen value and the required digit sum for that position.

1. Precompute all integers from $0$ to $5000$ and group them by their digit sum.
2. For each index $i$, we only consider numbers whose digit sum matches `required_sums[i]`.
3. Use DP with state `solve(i, prev)`:
   - number of valid ways to fill positions from $i$ onward
   - where `prev` is the previous chosen number in the non-decreasing sequence
4. Transition: for each valid candidate `num` with the correct digit sum and `num >= prev`, add `solve(i + 1, num)`.
5. Memoize this state to avoid recomputing the same subproblems.

This ensures every step remains valid, respects the non-decreasing constraint, and keeps the search space small because we only iterate over numbers that match the required digit sum.

### Example
There are $n = 3$ elements with the required sums of digits, `required_sums = [30, 31, 31]`.

These are the arrays that satisfy the conditions:
* `result = [4998, 4999, 4999]`
* `result = [4989, 4999, 4999]`
* `result = [4899, 4999, 4999]`
* `result = [3999, 4999, 4999]`

---

## Code Template

```cpp
#include <iostream>
#include <vector>

using namespace std;
