# 🛡️ 2812. Find the Safest Path in a Grid

## Problem Statement

You are given an `n × n` grid where:

- `0` represents an empty cell.
- `1` represents a thief.

You start from `(0,0)` and want to reach `(n-1,n-1)`.

The **safeness factor** of a path is defined as:

> The **minimum Manhattan distance** from any cell on the path to the nearest thief.

Our goal is to **maximize this minimum distance**.

---

# Key Observation

Instead of repeatedly calculating the distance from every cell to the nearest thief, we first preprocess the grid.

For every cell we compute:

```
distance[i][j] = Distance to the nearest thief
```

This can be done efficiently using **Multi-Source BFS**.

After this preprocessing, the problem becomes:

> Find a path whose **minimum cell value** is as large as possible.

---

# Step 1 : Multi-Source BFS

Instead of running BFS from every cell separately, we start BFS from **all thief cells simultaneously**.

### Example

Grid

```
0 0 1
0 0 0
0 0 0
```

Initially

```
INF INF 0
INF INF INF
INF INF INF
```

After Multi-Source BFS

```
2 1 0
3 2 1
4 3 2
```

Now every cell knows its distance from the nearest thief.

---

# Approach 1 : Binary Search + BFS

## Idea

Suppose we want to know:

> Is it possible to travel while maintaining a safeness factor of at least **X**?

A cell is usable only if

```
distance[i][j] >= X
```

Now simply perform BFS.

- If destination is reachable → safeness X is possible.
- Otherwise → impossible.

Since feasibility changes monotonically,

```
Possible
Possible
Possible
Impossible
Impossible
```

we can binary search the answer.

---

## Example

Distance matrix

```
2 1 0
3 2 1
4 3 2
```

Suppose

```
X = 2
```

Allowed cells become

```
✔ ✘ ✘
✔ ✔ ✘
✔ ✔ ✔
```

Run BFS.

If `(n-1,n-1)` is reachable,

```
answer >= 2
```

otherwise,

```
answer < 2
```

---

## Algorithm

1. Compute nearest thief distance using Multi-Source BFS.
2. Binary search on the answer.
3. For every mid value:
   - Run BFS.
   - Travel only through cells having distance ≥ mid.
4. Return the maximum feasible value.

---

## Complexity

### Multi-Source BFS

```
O(n²)
```

### Binary Search

Maximum distance ≤ `2n`

```
O(log n)
```

### BFS for every binary search iteration

```
O(n²)
```

### Overall

```
O(n² log n)
```

Space Complexity

```
O(n²)
```

---

# Approach 2 : Modified Dijkstra (Maximum Bottleneck Path)

This is a cleaner solution because it avoids binary search.

---

## Key Idea

Each cell already has a safety value.

Example

```
5 4 3
6 3 2
7 6 5
```

Suppose our path is

```
5 → 6 → 7 → 6 → 5
```

The path's safeness is

```
min(5,6,7,6,5)=5
```

Another path

```
5 → 4 → 3 → 2
```

has safeness

```
2
```

We want the path with the **largest minimum value**.

This is known as the **Maximum Bottleneck Path** problem.

---

## Modified Dijkstra

Instead of storing

```
(distance,row,col)
```

store

```
(currentSafeness,row,col)
```

Initially

```
(currentSafeness = distance[0][0])
```

Whenever moving to a neighbour,

```
newSafeness = min(currentSafeness,
                  distance[newRow][newCol])
```

because the weakest point of the path determines the entire path's safeness.

---

## Priority Queue

Always process the path having the **highest current safeness** first.

This is exactly opposite to normal Dijkstra.

Normal Dijkstra

```
Choose smallest distance.
```

Modified Dijkstra

```
Choose largest safeness.
```

---

## Example

Distance matrix

```
5 4 3
6 3 2
7 6 5
```

Start

```
(5,0,0)
```

Move Down

```
min(5,6)=5
```

Move Down

```
min(5,7)=5
```

Move Right

```
min(5,6)=5
```

Move Right

```
min(5,5)=5
```

Answer

```
5
```

---

## Algorithm

1. Compute nearest thief distance using Multi-Source BFS.
2. Use a Max Heap.
3. Store

```
(currentSafeness,row,col)
```

4. Expand the safest path first.
5. Update neighbour using

```
newSafeness = min(currentSafeness,
                  distance[neighbour])
```

6. Maintain

```
best[row][col]
```

which stores the maximum safeness achieved for every cell.

7. Once destination is popped from the priority queue,

```
return currentSafeness
```

---

## Complexity

### Multi-Source BFS

```
O(n²)
```

### Modified Dijkstra

```
O(n² log n)
```

### Overall

```
O(n² log n)
```

Space Complexity

```
O(n²)
```

---

# Comparison

| Binary Search + BFS | Modified Dijkstra |
|----------------------|------------------|
| Easy to understand | More elegant |
| Uses repeated BFS | Single traversal |
| Binary Search required | No Binary Search |
| O(n² log n) | O(n² log n) |

---

# Which Approach Should You Choose?

### Binary Search + BFS

✔ Easier to derive during interviews.

✔ Good if you recognize the monotonic property.

---

### Modified Dijkstra

✔ Cleaner implementation.

✔ No repeated BFS.

✔ Solves the general **Maximum Bottleneck Path** problem.

✔ Preferred by most experienced competitive programmers.

---

# Final Takeaway

Both approaches begin with the same preprocessing step:

> **Multi-Source BFS to compute the distance of every cell from the nearest thief.**

After that:

- **Approach 1** uses **Binary Search + BFS** to test whether a path exists for a given safeness factor.
- **Approach 2** treats the grid as a weighted graph and applies a **Modified Dijkstra (Maximum Bottleneck Path)** to directly maximize the minimum safety along the path.

Both achieve an overall time complexity of **O(n² log n)** and are accepted solutions for this problem.