# Maximum Machine Capacity Finder

## 🧩 Problem Description
You are given two integer arrays, `costs` and `capacity`, both of length $n$. 
- `costs[i]`: The purchase cost of the $i^{th}$ machine.
- `capacity[i]`: The performance capacity of the $i^{th}$ machine.
- `budget`: The total spending limit.

**Goal**: Select **at most two distinct** machines such that their total cost is **strictly less than** the budget. Return the maximum achievable total capacity.

---

## 🧠 Approaches

### 1️⃣ Brute Force ($O(N^2)$)
#### 💡 Idea
Check every possible single machine and every possible pair of distinct machines to find the maximum capacity that fits within the budget.

#### 🛠 Implementation
* **Single Item**: Iterate $i$ from $0 \dots n-1$. If `costs[i] < budget`, update `maxCap`.
* **Two Items**: Nested loops for $i$ and $j$ ($j > i$). If `costs[i] + costs[j] < budget`, update `maxCap`.

#### ⏱ Complexity
* **Time**: $O(N^2)$ — Inefficient for large datasets (e.g., $N > 10,000$).
* **Space**: $O(1)$.

---

### 2️⃣ Recursive Backtracking ($O(2^N)$)
#### 💡 Idea
Treat the problem as a variation of the 0/1 Knapsack problem where we are limited to selecting only 2 items.

#### 🛠 Implementation
A recursive function `solve(index, remainingBudget, itemsLeft)` explores two choices at each step:
1. **Skip**: Move to the next index without picking the machine.
2. **Take**: If budget allows, add capacity and move to the next index with `itemsLeft - 1`.

#### ⏱ Complexity
* **Time**: $O(2^N)$ — Exponential; only suitable for very small $N$.
* **Space**: $O(N)$ due to the recursion stack.

---

### 3️⃣ Optimized: Sorting + Prefix Max + Binary Search ($O(N \log N)$)
#### 💡 Idea
By sorting machines by cost, we can use **Binary Search** to instantly find the most expensive "partner" machine we can afford for any given machine.

#### 🛠 Algorithm
1.  **Pair & Sort**: Combine costs and capacities and sort them by cost.
2.  **Prefix Max**: Build a `preMax` array where `preMax[i]` is the highest capacity available in the range `[0...i]`.
3.  **Search**: 
    * For each machine $i$, calculate `remain = budget - costs[i] - 1`.
    * Use **Binary Search** to find the largest index `idx` where `costs[idx] <= remain`.
    * Use `preMax[idx]` to get the best partner in $O(1)$.

#### ⚖️ Why use Recursive Binary Search?
In this specific approach, a recursive Binary Search is utilized to provide **strict range control**. By passing explicit `l` (low) and `h` (high) boundaries, we can:
* **Limit the search space**: Easily restrict the search for a second machine to the range `[0, i-1]`.
* **Avoid Self-Selection**: Searching only to the left of the current index `i` ensures we pick **distinct** machines without extra conditional logic inside the loop.

#### ⏱ Complexity
* **Time**: $O(N \log N)$ — Dominated by sorting and $N$ binary searches.
* **Space**: $O(N)$ to store the sorted pairs and prefix maximums.

---

## 📊 Comparison Summary

| Approach | Technique | Time Complexity | Space Complexity | Suitable For |
| :--- | :--- | :--- | :--- | :--- |
| **Brute Force** | Nested Loops | $O(N^2)$ | $O(1)$ | Small $N$ |
| **Backtracking** | Recursion | $O(2^N)$ | $O(N)$ | Very Small $N$ |
| **Optimized** | Sort + BS + PreMax | $O(N \log N)$ | $O(N)$ | 🚀 **Large $N$ (Optimal)** |

---

## ⚠️ Key Constraints & Edge Cases
* **Strictly Less**: The condition is `cost < budget`, not `cost <= budget`. Always use `budget - 1` for bounds.
* **Distinct Machines**: The `idx == i` case must be handled (or avoided by range limiting) to ensure the same machine isn't counted twice.
* **Single Machine**: Always check if picking just one high-capacity machine is better than picking two smaller ones.

---
Happy Coding! 🚀
