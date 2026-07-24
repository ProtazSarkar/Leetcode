# Dijkstra's Shortest Path Algorithm

A clean guide explaining **Dijkstra's Algorithm**, its step-by-step logic, complexity details, and a curated list of LeetCode problems to practice.

---

## 📌 Overview

Dijkstra's Algorithm is a **greedy algorithm** used to find the shortest path from a single source vertex to all other vertices in a weighted graph. It works on both directed and undirected graphs, provided all edge weights are **non-negative**.

---

## 🛠️ The Core Logic (How It Works)

Dijkstra's algorithm keeps track of the currently known shortest distance from the source to every other node. It uses a **Min-Priority Queue** (or Min-Heap) to dynamically select the closest unvisited node.

### Step-by-Step Execution:

1. **Initialize Distances**  
   Set the distance to the **source node to 0** and the distance to all other nodes to **Infinity ($\infty$)**.

2. **Set Up Priority Queue**  
   Push the source node into a Min-Priority Queue as a pair: `(distance, node)` $\rightarrow$ `(0, source)`.

3. **Extract the Minimum Node**  
   Pop the node with the smallest cumulative distance from the priority queue. If this distance is greater than the already recorded shortest distance for this node, skip it (it's a stale entry).

4. **Relax Neighboring Edges**  
   For the current node, look at all its unvisited neighbors. Calculate the tentative distance to each neighbor:
   $$\text{New Distance} = \text{Current Node Distance} + \text{Edge Weight}$$
   If $\text{New Distance} < \text{Existing Neighbor Distance}$, update it and push `(New Distance, Neighbor)` into the priority queue.

5. **Repeat**  
   Repeat steps 3 and 4 until the priority queue is entirely empty.

---

## ⏱️ Complexity Analysis

* **Time Complexity:** $O((V + E) \log V)$, where $V$ is the number of vertices and $E$ is the number of edges. Extracting the minimum element and updating the Min-Heap takes $O(\log V)$ time.
* **Space Complexity:** $O(V + E)$ to store the graph (adjacency list) alongside $O(V)$ space for the distance array and the priority queue.

> ⚠️ **Important Constraint:** Dijkstra's algorithm **does not work with negative edge weights**. Negative weights can cause infinite cycles or incorrect greedy choices because the algorithm assumes a path can only get longer as more edges are added.

---

## 🚀 Recommended LeetCode Practice Problems

Here is a curated list of problems categorized by difficulty to help you master Dijkstra's algorithm.

### 🟢 Easy / Foundation
* **[LeetCode 743] Network Delay Time** — *The definitive introductory textbook problem for Dijkstra.*

### 🟡 Medium / Core Practice
* **[LeetCode 1514] Path with Maximum Probability** — *A great variant where you maximize probability (multiplication) instead of minimizing distance (addition).*
* **[LeetCode 1631] Path With Minimum Effort** — *Dijkstra applied to a matrix grid instead of a traditional node-edge graph.*
* **[LeetCode 787] Cheapest Flights Within K Stops** — *Shortest path with a constraint modification.*

### 🔴 Hard / Advanced Variants
* **[LeetCode 1976] Number of Ways to Arrive at Destination** — *Requires tracking how many unique paths achieve the minimum distance.*
* **[LeetCode 2290] Minimum Obstacle Removal to Reach Corner** — *Can be modeled with 0-1 BFS or a standard Dijkstra.*