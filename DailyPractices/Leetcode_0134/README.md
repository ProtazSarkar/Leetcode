# 134. Gas Station


## 📝 Problem Description

There are `n` gas stations along a circular route. Each station `i` provides `gas[i]` fuel, and it costs `cost[i]` fuel to travel to the next station `(i + 1)`. 

You start with an empty tank. Given the arrays `gas` and `cost`, return the starting gas station's index if you can complete a full circuit once in the clockwise direction. If no such station exists, return `-1`. The solution, if it exists, is guaranteed to be unique.

---

## 💡 Greedy Strategy

The problem can be solved in a single pass ($O(N)$) by observing two key mathematical properties:

### 1. The Global Condition
If the total amount of gas available across all stations is less than the total cost required to travel the entire circuit, it is physically impossible to complete the trip, regardless of the starting point.
> $\sum gas[i] < \sum cost[i] \implies \text{Return } -1$

### 2. The Local Restart Property
If you start at station `A` and run out of gas at station `B`, then **no station between A and B** can be a valid starting point. 
* This is because any station between A and B would start with an empty tank, whereas reaching that same station from A would have likely provided some surplus gas. If you couldn't reach B with surplus gas, you certainly won't reach it starting from zero.



---

## 🔄 Approach Comparison

The provided code includes two approaches: a Brute Force method and an Optimized Greedy method.

| Feature | Brute Force (Approach 2) | Optimized Greedy (Approach 1) |
| :--- | :--- | :--- |
| **Logic** | Checks every station as a potential start. | One pass; resets `start` when `tank < 0`. |
| **Time Complexity** | $O(N^2)$ | $O(N)$ |
| **Space Complexity** | $O(1)$ | $O(1)$ |
| **Outcome** | TLE (Time Limit Exceeded) on large inputs. | Passes efficiently. |

---

## 📊 Complexity Analysis (Optimized)

| Complexity | Notation | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N)$ | We iterate through the gas stations exactly once. |
| **Space Complexity** | $O(1)$ | We only use a few integer variables (`total`, `tank`, `start`). |

---

## 🛠️ Implementation Notes
* **`total`**: Tracks the cumulative balance of the entire trip. If it's negative at the end, the circuit is impossible.
* **`tank`**: Tracks the current fuel balance. If it drops below zero, it triggers a "restart" at the next available station.
* **Greedy Choice**: By setting `start = i + 1` whenever the tank fails, we skip all invalid starting points in a single linear scan.

---
