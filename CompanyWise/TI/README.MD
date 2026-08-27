# 🎯 Texas Instruments (TI) Campus Placement Preparation Guide

A structured 7-day preparation repository and study plan targeted at technical rounds for Texas Instruments. This collection covers **70 high-frequency LeetCode problems** spanning low-level bit manipulation, data structures, algorithms, and SQL, along with core C/Systems conceptual refreshers.

---

## 📌 Focus Distribution

Unlike standard web/software tech interviews, TI evaluates candidate proficiency at the **hardware-software boundary**, low-level efficiency, and relational querying.

| Core Area | Weight | Key Skills Tested |
| :--- | :--- | :--- |
| **Bit Manipulation & Low-Level C** | **30%** | Bit masks, shifting, register flags, endianness, pointer arithmetic |
| **Arrays & Two Pointers** | **20%** | Sliding window, matrix operations, search/sort optimization |
| **Linked Lists, Trees & Graphs** | **20%** | Pointer manipulation, LCA, BFS/DFS, cycle detection |
| **SQL & Relational Queries** | **15%** | Joins, aggregation, subqueries, Window functions |
| **OS & Memory Fundamentals** | **15%** | Stack vs Heap, `volatile`, macro hazards, Dynamic Programming |

---

## 📚 70 Selected LeetCode Problems

### ⚡ Module 1: Bit Manipulation (15 Problems)
> *Essential for microcontrollers, firmware, and embedded system applications.*

| # | Problem | Difficulty | Key Concept |
| :-: | :--- | :-: | :--- |
| 191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | Easy | Brian Kernighan's Algorithm (`n & (n - 1)`) |
| 190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits/) | Easy | Bitwise shifting & masking |
| 136 | [Single Number](https://leetcode.com/problems/single-number/) | Easy | XOR properties (`a ^ a = 0`) |
| 137 | [Single Number II](https://leetcode.com/problems/single-number-ii/) | Medium | Bit counting / State machine with XOR & AND |
| 260 | [Single Number III](https://leetcode.com/problems/single-number-iii/) | Medium | Partitioning via lowest set bit |
| 231 | [Power of Two](https://leetcode.com/problems/power-of-two/) | Easy | Bitwise AND check (`(n & (n - 1)) == 0`) |
| 338 | [Counting Bits](https://leetcode.com/problems/counting-bits/) | Easy | DP + Most/Least Significant Bit |
| 268 | [Missing Number](https://leetcode.com/problems/missing-number/) | Easy | Sum difference or XOR accumulators |
| 461 | [Hamming Distance](https://leetcode.com/problems/hamming-distance/) | Easy | XOR + Population count |
| 477 | [Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance/) | Medium | Column-wise bit counting |
| 201 | [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/) | Medium | Finding common binary prefix |
| 371 | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) | Medium | Half adder logic (XOR for sum, AND for carry) |
| 187 | [Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/) | Medium | Bitmask encoding (2-bit per nucleotide) |
| 29 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) | Medium | Exponential subtraction via left shifts |
| 89 | [Gray Code](https://leetcode.com/problems/gray-code/) | Medium | Binary to Gray code (`i ^ (i >> 1)`) |

---

### 🔍 Module 2: Arrays, Pointers & Sliding Window (12 Problems)

| # | Problem | Difficulty | Key Concept |
| :-: | :--- | :-: | :--- |
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | Easy | Hash map lookup / complement check |
| 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | Easy | Two-pointer read/write heads |
| 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | Easy | In-place backward merge |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | Easy | Single pass tracking minimum price |
| 53 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | Medium | Kadane’s Algorithm |
| 15 | [3Sum](https://leetcode.com/problems/3sum/) | Medium | Sorting + Two pointers with duplicate skipping |
| 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | Medium | Shrinking two-pointer boundary |
| 283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | Easy | Non-zero element compaction |
| 209 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | Medium | Dynamic sliding window expansion/contraction |
| 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Medium | Sliding window + Character index map |
| 56 | [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | Medium | Sorting by start time + Greedy merge |
| 238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | Medium | Prefix & Suffix product sweeps |

---

### 🔗 Module 3: Linked Lists (8 Problems)

| # | Problem | Difficulty | Key Concept |
| :-: | :--- | :-: | :--- |
| 206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | Easy | Iterative 3-pointer manipulation |
| 141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | Easy | Floyd's Tortoise and Hare |
| 142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) | Medium | Cycle detection & entry point math |
| 21 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | Easy | Dummy head node pointer stitching |
| 19 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | Medium | Two-pointer gap strategy |
| 160 | [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) | Easy | Dual-pointer traversal path length alignment |
| 143 | [Reorder List](https://leetcode.com/problems/reorder-list/) | Medium | Find midpoint + reverse second half + interleave |
| 138 | [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) | Medium | Interleaved duplicate nodes or Hash map binding |

---

### 🌲 Module 4: Trees, Graph & Search (12 Problems)

| # | Problem | Difficulty | Key Concept |
| :-: | :--- | :-: | :--- |
| 102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | Medium | Queue-based BFS |
| 104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | Easy | Post-order DFS |
| 226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) | Easy | Recursive left/right child swap |
| 98 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | Medium | Range bounds propagation `(min, max)` |
| 236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | Medium | Recursive subtree search aggregation |
| 100 | [Same Tree](https://leetcode.com/problems/same-tree/) | Easy | Simultaneous Structural Traversal |
| 543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) | Easy | Height calculation side-effects |
| 200 | [Number of Islands](https://leetcode.com/problems/number-of-islands/) | Medium | 2D Grid DFS / BFS sink operation |
| 207 | [Course Schedule](https://leetcode.com/problems/course-schedule/) | Medium | Topological Sort / Kahn's Algorithm / Cycle Detection |
| 743 | [Network Delay Time](https://leetcode.com/problems/network-delay-time/) | Medium | Dijkstra's Shortest Path |
| 33 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | Medium | Modified Binary Search on partitioned sorted halves |
| 74 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) | Medium | Virtual 1D binary search (`matrix[mid / n][mid % n]`) |

---

### ⚙️ Module 5: Dynamic Programming & Backtracking (8 Problems)

| # | Problem | Difficulty | Key Concept |
| :-: | :--- | :-: | :--- |
| 70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | Easy | Base Fibonacci recurrence |
| 322 | [Coin Change](https://leetcode.com/problems/coin-change/) | Medium | Bottom-up Unbounded Knapsack |
| 300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | Medium | Patience sorting + Binary Search ($O(N \log N)$) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) | Medium | 2D Grid DP matching |
| 134 | [Gas Station](https://leetcode.com/problems/gas-station/) | Medium | Single-pass greedy total deficit balance |
| 46 | [Permutations](https://leetcode.com/problems/permutations/) | Medium | In-place swapping backtracking |
| 78 | [Subsets](https://leetcode.com/problems/subsets/) | Medium | Cascading or Bitmask generation ($2^N$) |
| 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | Medium | Open/Close count balance backtracking |

---

### 🗄️ Module 6: SQL & Database Queries (15 Problems)

| # | Problem | Difficulty | Key Concept |
| :-: | :--- | :-: | :--- |
| 175 | [Combine Two Tables](https://leetcode.com/problems/combine-two-tables/) | Easy | Basic `LEFT JOIN` |
| 176 | [Second Highest Salary](https://leetcode.com/problems/second-highest-salary/) | Medium | `OFFSET 1` / Subqueries handling `NULL` |
| 177 | [Nth Highest Salary](https://leetcode.com/problems/nth-highest-salary/) | Medium | Stored procedure logic / `DENSE_RANK()` |
| 178 | [Rank Scores](https://leetcode.com/problems/rank-scores/) | Medium | `DENSE_RANK() OVER (ORDER BY score DESC)` |
| 180 | [Consecutive Numbers](https://leetcode.com/problems/consecutive-numbers/) | Medium | Self Joins or `LEAD()` / `LAG()` window functions |
| 181 | [Employees Earning More Than Their Managers](https://leetcode.com/problems/employees-earning-more-than-their-managers/) | Easy | Self `JOIN` on `ManagerId` |
| 182 | [Duplicate Emails](https://leetcode.com/problems/duplicate-emails/) | Easy | `GROUP BY ... HAVING COUNT(*) > 1` |
| 183 | [Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/) | Easy | `LEFT JOIN` with `WHERE ... IS NULL` or `NOT IN` |
| 184 | [Department Highest Salary](https://leetcode.com/problems/department-highest-salary/) | Medium | `IN` clause with subquery multi-column matching |
| 185 | [Department Top Three Salaries](https://leetcode.com/problems/department-top-three-salaries/) | Hard | Window functions (`DENSE_RANK() <= 3`) |
| 196 | [Delete Duplicate Emails](https://leetcode.com/problems/delete-duplicate-emails/) | Easy | Self `DELETE JOIN` keeping min ID |
| 197 | [Rising Temperature](https://leetcode.com/problems/rising-temperature/) | Easy | Date functions (`DATEDIFF` / `AGE` / `INTERVAL`) |
| 570 | [Managers with at Least 5 Direct Reports](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/) | Medium | Subquery aggregation with `HAVING` |
| 596 | [Classes More Than 5 Students](https://leetcode.com/problems/classes-more-than-5-students/) | Easy | `COUNT(DISTINCT student)` aggregation |
| 626 | [Exchange Seats](https://leetcode.com/problems/exchange-seats/) | Medium | `CASE WHEN` logic using ID modulo |

---

## 🛠️ Low-Level C Snippet Refreshers

TI technical interviews frequently feature short C code evaluation snippets. Keep these common traps in mind:

### 1. Macro Expansion Side Effects
```c
#define SQUARE(x) x * x

int val = SQUARE(2 + 3); 
// Expands to: 2 + 3 * 2 + 3 = 11 (NOT 25)
// Fix: Always wrap parameters: #define SQUARE(x) ((x) * (x))