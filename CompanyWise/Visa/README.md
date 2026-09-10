# 🚀 Visa 2027 Tech Summer Internship Prep: 70 LeetCode & SQL Tracker

A structured repository tracking solutions to the top 70 LeetCode & OA problems (50 DSA + 20 SQL) tailored for the **Visa Software Engineering Internship** assessment and technical interviews.

---

## 📌 Repository Overview

This repository contains optimal implementations, complexity analyses, and notes for core Data Structures, Algorithms, and Relational Database queries.

* **Target Role:** Software Engineering Intern (Visa 2027 Summer Internship Program)
* **Languages Used:** C++ / Python / Java / MySQL
* **Focus Areas:** Visa OA Real Questions (Drone Walk, Peak Sum, Server Partitioning), Prefix Sums + Modulo, Monotonic Deques, Binary Search on Answer, Dynamic Programming, and SQL Window Functions.

---

## 🎯 Visa OA Direct & Pattern-Matched Questions

| Question / Pattern | Primary Concept | Difficulty | Solution | Time | Space | Status |
|---|---|---|---|---|---|---|
| **OA Q1: Sum of "Peak" Elements** | Neighbor Comparisons / Array | Easy | [Link](#) | $O(N)$ | $O(1)$ | ⬜ Pending |
| **OA Q2: Drone's Walk** | Greedy Reach & Refuel Range | Medium | [Link](#) | $O(M)$ | $O(1)$ | ⬜ Pending |
| **OA Q3: [LC 1438] Longest Subsegment** | Monotonic Deque / Sliding Window | Medium | [Link](#) | $O(N)$ | $O(N)$ | ⬜ Pending |
| **OA Q4: [LC 410] Server Allocation** | Binary Search on Answer | Hard | [Link](#) | $O(N \log (\sum \text{load}))$ | $O(1)$ | 🟩 Done |
| **[LC 1546] Max Non-Overlapping Subarrays** | Prefix Sum + Hash Set | Medium | [Link](#) | $O(N)$ | $O(N)$ | 🟩 Done |
| **[LC 1589] Max Sum of Any Permutation** | Difference Array (Line Sweep) | Medium | [Link](#) | $O(N \log N + K)$ | $O(N)$ | 🟩 Done |
| **[LC 1590] Make Sum Divisible by P** | Prefix Sum + Modulo Map | Medium | [Link](#) | $O(N)$ | $O(N)$ | 🟩 Done |
| **[LC 1658] Min Ops to Reduce X to Zero** | Sliding Window / Subarray | Medium | [Link](#) | $O(N)$ | $O(1)$ | 🟩 Done |
| **[LC 1664] Ways to Make a Fair Array** | Even/Odd Prefix Sum Shift | Medium | [Link](#) | $O(N)$ | $O(1)$ | 🟩 Done |

---

## 🧠 Data Structures & Algorithms

### Arrays, Prefix Sums & Two Pointers
| # | Problem | Difficulty | Solution | Time | Space | Status |
|---|---|---|---|---|---|---|
| 001 | [1. Two Sum](https://leetcode.com/problems/two-sum/) | Easy | [Link](#) | $O(N)$ | $O(N)$ | 🟩 Done |
| 015 | [15. 3Sum](https://leetcode.com/problems/3sum/) | Medium | [Link](#) | $O(N^2)$ | $O(1)$ | ⬜ Pending |
| 049 | [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/) | Medium | [Link](#) | $O(N \cdot K \log K)$ | $O(N \cdot K)$ | ⬜ Pending |
| 053 | [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | Medium | [Link](#) | $O(N)$ | $O(1)$ | ⬜ Pending |
| 056 | [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) | Medium | [Link](#) | $O(N \log N)$ | $O(N)$ | ⬜ Pending |
| 167 | [167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | Medium | [Link](#) | $O(N)$ | $O(1)$ | ⬜ Pending |
| 523 | [523. Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) | Medium | [Link](#) | $O(N)$ | $O(N)$ | ⬜ Pending |
| 560 | [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | Medium | [Link](#) | $O(N)$ | $O(N)$ | ⬜ Pending |
| 2491 | [2491. Divide Players Into Teams of Equal Skill](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/) | Medium | [Link](#) | $O(N \log N)$ | $O(1)$ | ⬜ Pending |

---

### Binary Search on Answer
| # | Problem | Difficulty | Solution | Time | Space | Status |
|---|---|---|---|---|---|---|
| 875 | [875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) | Medium | [Link](#) | $O(N \log(\max A))$ | $O(1)$ | ⬜ Pending |
| 1011 | [1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | Medium | [Link](#) | $O(N \log(\sum W))$ | $O(1)$ | ⬜ Pending |
| 1283 | [1283. Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/) | Medium | [Link](#) | $O(N \log(\max A))$ | $O(1)$ | ⬜ Pending |
| 1482 | [1482. Minimum Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) | Medium | [Link](#) | $O(N \log(\max A))$ | $O(1)$ | ⬜ Pending |
| 1552 | [1552. Magnetic Force Between Two Balls](https://leetcode.com/problems/magnetic-force-between-two-balls/) | Medium | [Link](#) | $O(N \log(\text{range}))$ | $O(1)$ | ⬜ Pending |

---

### Strings & Monotonic Queue / Sliding Window
| # | Problem | Difficulty | Solution | Time | Space | Status |
|---|---|---|---|---|---|---|
| 003 | [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Medium | [Link](#) | $O(N)$ | $O(K)$ | ⬜ Pending |
| 005 | [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | Medium | [Link](#) | $O(N^2)$ | $O(1)$ | ⬜ Pending |
| 020 | [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | Easy | [Link](#) | $O(N)$ | $O(N)$ | ⬜ Pending |
| 076 | [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | Hard | [Link](#) | $O(N)$ | $O(K)$ | ⬜ Pending |
| 227 | [227. Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/) | Medium | [Link](#) | $O(N)$ | $O(N)$ | ⬜ Pending |
| 1209 | [1209. Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/) | Medium | [Link](#) | $O(N)$ | $O(N)$ | ⬜ Pending |

---

### Matrix Operations, Trees & Graphs
| # | Problem | Difficulty | Solution | Time | Space | Status |
|---|---|---|---|---|---|---|
| 036 | [36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) | Medium | [Link](#) | $O(1)$ | $O(1)$ | ⬜ Pending |
| 048 | [48. Rotate Image](https://leetcode.com/problems/rotate-image/) | Medium | [Link](#) | $O(N^2)$ | $O(1)$ | ⬜ Pending |
| 054 | [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | Medium | [Link](#) | $O(M \cdot N)$ | $O(1)$ | ⬜ Pending |
| 098 | [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | Medium | [Link](#) | $O(N)$ | $O(H)$ | ⬜ Pending |
| 200 | [200. Number of Islands](https://leetcode.com/problems/number-of-islands/) | Medium | [Link](#) | $O(M \cdot N)$ | $O(M \cdot N)$ | ⬜ Pending |
| 207 | [207. Course Schedule](https://leetcode.com/problems/course-schedule/) | Medium | [Link](#) | $O(V + E)$ | $O(V + E)$ | ⬜ Pending |
| 236 | [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | Medium | [Link](#) | $O(N)$ | $O(H)$ | ⬜ Pending |

---

### Dynamic Programming & Monotonic Stacks
| # | Problem | Difficulty | Solution | Time | Space | Status |
|---|---|---|---|---|---|---|
| 042 | [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | Hard | [Link](#) | $O(N)$ | $O(1)$ | ⬜ Pending |
| 084 | [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) | Hard | [Link](#) | $O(N)$ | $O(N)$ | ⬜ Pending |
| 139 | [139. Word Break](https://leetcode.com/problems/word-break/) | Medium | [Link](#) | $O(N^2 \cdot K)$ | $O(N)$ | ⬜ Pending |
| 146 | [146. LRU Cache](https://leetcode.com/problems/lru-cache/) | Medium | [Link](#) | $O(1)$ | $O(C)$ | ⬜ Pending |
| 198 | [198. House Robber](https://leetcode.com/problems/house-robber/) | Medium | [Link](#) | $O(N)$ | $O(1)$ | ⬜ Pending |
| 322 | [322. Coin Change](https://leetcode.com/problems/coin-change/) | Medium | [Link](#) | $O(N \cdot A)$ | $O(A)$ | ⬜ Pending |
| 739 | [739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) | Medium | [Link](#) | $O(N)$ | $O(N)$ | ⬜ Pending |
| 1143 | [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) | Medium | [Link](#) | $O(M \cdot N)$ | $O(M \cdot N)$ | ⬜ Pending |

---

## 🗄️ SQL & Database Queries (20 Questions)

| # | Problem | Focus Concept | Difficulty | Solution | Status |
|---|---|---|---|---|---|
| 175 | [175. Combine Two Tables](https://leetcode.com/problems/combine-two-tables/) | LEFT JOIN | Easy | [Link](#) | ⬜ Pending |
| 176 | [176. Second Highest Salary](https://leetcode.com/problems/second-highest-salary/) | Subquery / LIMIT | Medium | [Link](#) | ⬜ Pending |
| 177 | [177. N-th Highest Salary](https://leetcode.com/problems/n-th-highest-salary/) | User Variables / DENSE_RANK | Medium | [Link](#) | ⬜ Pending |
| 178 | [178. Rank Scores](https://leetcode.com/problems/rank-scores/) | Window Functions (`DENSE_RANK`) | Medium | [Link](#) | ⬜ Pending |
| 180 | [180. Consecutive Numbers](https://leetcode.com/problems/consecutive-numbers/) | Self JOIN / `LEAD`/`LAG` | Medium | [Link](#) | ⬜ Pending |
| 181 | [181. Employees Earning More Than Managers](https://leetcode.com/problems/employees-earning-more-than-their-managers/) | Self JOIN | Easy | [Link](#) | ⬜ Pending |
| 182 | [182. Duplicate Emails](https://leetcode.com/problems/duplicate-emails/) | `GROUP BY` + `HAVING` | Easy | [Link](#) | ⬜ Pending |
| 183 | [183. Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/) | `NOT IN` / `LEFT JOIN` | Easy | [Link](#) | ⬜ Pending |
| 184 | [184. Department Highest Salary](https://leetcode.com/problems/department-highest-salary/) | Subquery / `IN` | Medium | [Link](#) | ⬜ Pending |
| 185 | [185. Department Top Three Salaries](https://leetcode.com/problems/department-top-three-salaries/) | `DENSE_RANK()` Partition | Hard | [Link](#) | ⬜ Pending |
| 550 | [550. Game Play Analysis IV](https://leetcode.com/problems/game-play-analysis-iv/) | Aggregate / Date Functions | Medium | [Link](#) | ⬜ Pending |
| 570 | [570. Managers with at Least 5 Direct Reports](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/) | `GROUP BY` + Subquery | Medium | [Link](#) | ⬜ Pending |
| 585 | [585. Investments in 2016](https://leetcode.com/problems/investments-in-2016/) | Window Functions & Filtering | Medium | [Link](#) | ⬜ Pending |
| 601 | [601. Human Traffic of Stadium](https://leetcode.com/problems/human-traffic-of-stadium/) | Window Functions / Island Problem | Hard | [Link](#) | ⬜ Pending |
| 608 | [608. Tree Node](https://leetcode.com/problems/tree-node/) | `CASE WHEN` Logic | Medium | [Link](#) | ⬜ Pending |
| 627 | [627. Swap Salary](https://leetcode.com/problems/swap-salary/) | Conditional `UPDATE` | Easy | [Link](#) | ⬜ Pending |
| 1158 | [1158. Market Analysis I](https://leetcode.com/problems/market-analysis-i/) | `LEFT JOIN` with Filtering | Medium | [Link](#) | ⬜ Pending |
| 1174 | [1174. Immediate Food Delivery II](https://leetcode.com/problems/immediate-food-delivery-ii/) | Subquery Windowing | Medium | [Link](#) | ⬜ Pending |
| 1193 | [1193. Monthly Transactions I](https://leetcode.com/problems/monthly-transactions-i/) | Aggregation & Formatting | Medium | [Link](#) | ⬜ Pending |
| 1204 | [1204. Last Person to Fit in the Bus](https://leetcode.com/problems/last-person-to-fit-in-the-bus/) | Running Sum (`SUM() OVER()`) | Medium | [Link](#) | ⬜ Pending | 