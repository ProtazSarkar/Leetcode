# 🚀 Number of Paths with Max Score (LeetCode 1301)

## 📝 Problem Overview
Given a square `board` of characters, you start at the bottom-right corner marked with `'S'` and want to reach the top-left corner marked with `'E'`. 
* You can move **up**, **left**, or **diagonally up-left**.
* Cells contain numeric digits (`'1'` to `'9'`) representing points, obstacles (`'X'`), or start/end markers (`'S'`, `'E'`) worth `0` points.
* Your goal is to return a list of two integers: **`[maximum_score, number_of_paths_to_get_it]`**. 
* Since the number of paths can be massive, return the path count **modulo $10^9 + 7$**. If the target is unreachable, return `[0, 0]`.

---

## 💡 Core Concepts Used

### 1. Dynamic Programming (DP)
This problem has an **optimal substructure** and **overlapping subproblems**, making it a textbook candidate for Dynamic Programming. Instead of finding all paths from scratch (which would take exponential time), we compute the optimal solution for smaller sub-squares and use them to build the answer for the entire board.

We maintain two matrices:
*   `dp_score[i][j]`: Stores the maximum score possible to reach cell `(i, j)` from the starting position `(n-1, n-1)`.
*   `dp_path[i][j]`: Stores the total number of paths that achieve that specific `max_score` at cell `(i, j)`.

### 2. Multi-Objective State Tracking
Unlike traditional shortest-path or maximum-weight path problems where you only track one value (e.g., maximum sum), this problem requires tracking **two dependent variables simultaneously**:
*   The optimal value (Max Score).
*   The frequency of that optimal value (Path Count).

When evaluating transitions from neighbor cells, we use the following state rules:
```text
If neighbor_score > current_max:
    current_max = neighbor_score
    path_count = neighbor_path_count (Reset count to this new optimal path)

If neighbor_score == current_max:
    path_count += neighbor_path_count (Accumulate paths yielding the same max)