# LeetCode 3650 – Minimum Cost to Convert String 
# I
## 🧩 Problem Description
You are given two strings `source` and `target` 
of equal length $n$. You are also given three 
arrays: `original`, `changed`, and `cost`, where 
`cost[i]` represents the cost of changing the 
character `original[i]` to `changed[i]`. Each 
change is **directed** and can be applied 
**multiple times** (chaining transformations, 
e.g., 'a' → 'b' → 'c'). Your task is to find the 
**minimum total cost** to convert `source` into 
`target`. If it is **impossible**, return `-1`. 
---
## 🔍 Key Observations
* **Character Independence**: Each character 
conversion at index $i$ is independent of other 
indices. * **Graph Nodes**: Since characters are 
lowercase English letters, the graph has exactly 
**26 nodes** ('a' to 'z'). * **Shortest Path 
Problem**: Finding the minimum cost to change 
character $A$ to $B$ is a shortest path problem 
in a weighted directed graph. ---
## 🧠 Approaches
### 1️⃣ Brute Force (DFS / Backtracking)
#### 💡 Idea
For every character at each index where 
`source[i] != target[i]`, perform a Depth First 
Search (DFS) to explore every possible 
transformation path until the target character 
is reached.
#### 🛠 Algorithm
1.  Build an adjacency list where each node 
points to its possible transformations. 2.  For 
each mismatching character, run DFS to find all 
paths to the target. 3.  Use a `visited` set to 
prevent infinite loops in cycles. 4.  Keep track 
of the minimum cost found across all paths.
#### ⏱ Complexity
* **Time Complexity**: $O(N \times 26!)$ — In 
the worst case, exploring all permutations for 
every index. * **Space Complexity**: $O(26)$ — 
Recursion stack depth. * **Verdict**: ❌ **TLE 
(Time Limit Exceeded)**. It recomputes the same 
character transitions millions of times. ---
### 2️⃣ Dijkstra per Character (Single-Source 
### Shortest Path)
#### 💡 Idea
Instead of recomputing paths for every index, 
run **Dijkstra’s Algorithm** starting from each 
unique character present in the `source` string 
to find the shortest path to all possible target 
characters.
#### 🛠 Algorithm
1.  Build a graph from the `original`, 
`changed`, and `cost` arrays. 2.  For each 
unique character $c \in \{'a' \dots 'z'\}$:
    * Run Dijkstra to find the shortest distance 
    to all other 25 characters. * Store these 
    results in a 2D array `minCost[26][26]`.
3.  Iterate through `source` and `target`, 
summing the precomputed costs.
#### ⏱ Complexity
* **Time Complexity**: $O(26 \cdot (E \log 26) + 
N)$ — Where $E$ is the number of transformation 
rules. * **Space Complexity**: $O(26^2)$ — To 
store the distance matrix. * **Verdict**: ⚠️ 
**Passes**, but repetitive Dijkstra calls are 
less efficient than a global matrix approach. 
---
### 3️⃣ Optimized Approach (Floyd–Warshall 
### Precomputation)
#### 💡 Idea
Since the number of nodes is very small 
($V=26$), the **Floyd-Warshall algorithm** is 
the most efficient way to precompute **all-pairs 
shortest paths** in a single pass.
#### 🛠 Algorithm
1.  Create a $26 \times 26$ matrix `dist` 
initialized to $\infty$. Set `dist[i][i] = 0`. 
2.  For each transformation `(original[k], 
changed[k], cost[k])`, set: $dist[u][v] = 
\min(dist[u][v], cost[k])$. 3.  **Run 
Floyd-Warshall**:
    ```cpp for (int k = 0; k < 26; ++k) for (int 
        i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j) if 
                (dist[i][k] != INF && dist[k][j] 
                != INF)
                    dist[i][j] = min(dist[i][j], 
                    dist[i][k] + dist[k][j]);
    ``` 4.  **Sum the costs**: `total += 
dist[source[i]][target[i]]`. Return `-1` if any 
required path is $\infty$.
#### ⏱ Complexity
* **Time Complexity**: $O(26^3 + N)$ — The 
$26^3$ part is a constant (17,576), making this 
effectively $O(N)$. * **Space Complexity**: 
$O(1)$ — We use a fixed $26 \times 26$ matrix. * 
**Verdict**: ✅ **Optimal**. ---
## 📊 Comparison Summary
| Approach | Technique | Time Complexity | Space 
| Complexity | Suitable |
| :--- | :--- | :--- | :--- | :--- |
| **Brute Force** | DFS | $O(N \cdot 26!)$ | 
| $O(26)$ | ❌ TLE | **Dijkstra** | SSSP (per 
| char) | $O(26 \cdot E \log 26 + N)$ | 
| $O(26^2)$ | ✅ Passes | **Floyd-Warshall** | 
| All-Pairs Shortest Path | $O(26^3 + N)$ | 
| $O(26^2)$ | 🚀 Optimal |
---
## Final Notes
* **Initial State**: Always use a large value 
for infinity (e.g., `1e14` for `long long`) to 
avoid overflow during the `dist[i][k] + 
dist[k][j]` step. * **Edge Cases**: Multiple 
rules can exist for the same character pair; 
always pick the minimum cost when initializing 
the matrix. Happy coding 🚀
