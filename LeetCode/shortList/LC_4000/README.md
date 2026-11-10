# LC 4000 - Shortlist Problem

## Question

You are given:
- an integer array `nums`
- a parallel array `locked` that indicates whether the corresponding positions are blocked / must be paid to unlock
- an integer `k` representing the maximum allowed total cost

The goal is to determine the minimum number of operations needed to make the array valid while respecting the budget `k`.

From the implementation, the core idea is:
- if the running maximum seen so far exceeds the expected position (`i + 1`), then the current prefix is invalid and must be repaired,
- each repair costs the sum of the two adjacent `locked` values,
- after the greedy repair pass, the remaining work is equivalent to counting how many inversions still exist in the array,
- if the total cost goes above `k`, the answer is `-1`.

In other words, the problem is to find the minimum cost to repair the array and sort it into a valid order without exceeding the budget.

## Solution approach

### 1) Greedy invalid-prefix repair

The first loop scans the array left to right and keeps track of the maximum value seen so far:

```cpp
int mx = 0;
for (int i = 0; i < n - 1; i++) {
    mx = max(mx, nums[i]);
    if (mx > i + 1) {
        ans += locked[i] + locked[i + 1];
        locked[i] = locked[i + 1] = 0;
    }
}
```

If at some position `i`, the running maximum is greater than `i + 1`, then this indicates the prefix is out of order / structurally invalid. In that case:
- the cost of fixing the neighboring locked positions is added,
- those positions are reset to zero so they are no longer counted again.

This is a greedy pass: whenever a prefix becomes invalid, we immediately pay the local repair cost.

### 2) Budget check

After this greedy repair stage:

```cpp
if (ans > k) return -1;
```

If the accumulated repair cost already exceeds the available budget, no valid configuration is possible.

### 3) Count remaining inversions

The second part of the solution deals with the remaining disorder in the array:

```cpp
vector<int> sorted;
for (int x : nums) {
    auto it = upper_bound(sorted.begin(), sorted.end(), x);
    ans += sorted.end() - it;
    sorted.insert(it, x);
}
```

This is the standard inversion-counting pattern using an ordered container:
- `sorted` stores the processed values in sorted order,
- `upper_bound(sorted.begin(), sorted.end(), x)` finds where `x` should be inserted,
- the number of elements after that point are exactly the values greater than `x` that have already appeared,
- adding them counts the inversions contributed by `x`.

So the final answer is:

`repair cost + total inversions`

## Why this works

The algorithm combines two observations:
1. A local invalid prefix must be fixed immediately, and the cost for the adjacent locked positions can be charged greedily.
2. The remaining disorder in the array is exactly captured by the inversion count.

Thus, the total value computed by the program is the minimum cost required to repair the array under the given budget constraint.

## Complexity

- Greedy repair pass: `O(n)`
- Inversion counting via ordered insertion: `O(n^2)` in the worst case (because of insertion into a vector)
- Overall: `O(n^2)` time
- Extra space: `O(n)` for the sorted list

## Reference

Implementation file: `main.cpp`
