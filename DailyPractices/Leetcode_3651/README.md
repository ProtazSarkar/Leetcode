# Minimum Cost Grid Path with Teleportation 🚀

Efficient solution to a modified shortest-path problem on a 2D grid where limited teleportation is permitted.

---

## 🧩 Problem Statement

You are given an `m x n` grid and an integer `k`. You start at the top-left cell `(0, 0)` and must reach the bottom-right cell `(m - 1, n - 1)` with the **minimum possible cost**.

### Movement Rules

1.  **Normal Move**: Move **Right** `(i, j + 1)` or **Down** `(i + 1, j)`.
    * **Cost**: The value of the destination cell `grid[x][y]`.
2.  **Teleportation**: Jump from your current cell `(i, j)` to **any** other cell `(x, y)` in the grid, provided that `grid[x][y] <= grid[i][j]`.
    * **Cost**: `0`.
    * **Limit**: You can use this move at most `k` times.

---

## 🧠 Solution Approach: 3D Dynamic Programming

To solve this, we use a 3D DP table where we track our position on the grid and the number of teleportations remaining.

### DP State Definition
Let $DP[i][j][rem]$ be the minimum cost to reach cell $(i, j)$ having exactly $rem$ teleportations left to use.

### Base Case
* Starting point: $DP[0][0][k] = grid[0][0]$
* All other states: Initialize to $\infty$.

### Transitions

For every cell $(i, j)$ and every available teleportation count $rem$:

1.  **Normal Movement (Right/Down)**:
    * If moving from $(i-1, j)$ to $(i, j)$: 
        $$DP[i][j][rem] = \min(DP[i][j][rem], DP[i-1][j][rem] + grid[i][j])$$
    * If moving from $(i, j-1)$ to $(i, j)$: 
        $$DP[i][j][rem] = \min(DP[i][j][rem], DP[i][j-1][rem] + grid[i][j])$$

2.  **Teleportation**:
    * Since a teleport costs $0$ and can land on any cell $(i, j)$ where $grid[i][j] \le grid[prev\_i][prev\_j]$, we can optimize by tracking the minimum cost reached at any cell with a specific grid value.
    * If $rem > 0$, we can teleport to $(i, j)$ from any cell that satisfies the value condition.

---

## 📊 Complexity Analysis

* **Time Complexity**: $O(m \cdot n \cdot k)$
    * We iterate through each cell of the grid for each possible value of $k$.
* **Space Complexity**: $O(m \cdot n \cdot k)$ 
    * Required to store the 3D DP table. This can be optimized to $O(m \cdot n)$ in some implementations if $k$ is handled iteratively.

---

## 💻 Implementation Highlights

* **Initialization**: The grid is processed to ensure we account for the cost of the starting cell $(0,0)$.
* **Boundary Checks**: Ensure indices do not go out of bounds during transitions.
* **Result**: The answer is $\min(DP[m-1][n-1][rem])$ for all $0 \le rem \le k$.
