# Tarjan's Bridge-Finding Algorithm (Critical Connections)

## Problem Description
In a connected network of $n$ servers, a **critical connection** (or **bridge**) is an edge whose removal disconnects the graph, making it impossible for some servers to communicate with others. This algorithm finds all such critical connections in a single traversal pass.

---

## 💡 Core Concept & Approach
A naive approach would remove each edge one by one and run a Breadth-First Search (BFS) or Depth-First Search (DFS) to see if the graph remains connected. However, that takes $O(E \times (V + E))$ time, which triggers a **Time Limit Exceeded (TLE)** on large graphs.

Instead, **Tarjan's Algorithm** finds all bridges in a single DFS pass ($O(V + E)$) by maintaining two tracking metrics for each node `u`:
1. **`discovery_time[u]`**: The absolute timestamp counter tracking when node `u` was first visited.
2. **`low[u]`**: The lowest `discovery_time` reachable from `u` by exploring its DFS subtree or taking a single back-edge shortcut up to an ancestor.

### The Bridge Condition
While traversing from a parent `node` to a child `neighbor`:
* If the subtree rooted at `neighbor` has no back-edges pointing to `node` or any of its ancestors, it means `low[neighbor]` will remain strictly greater than `discovery_time[node]`.
* If **`low[neighbor] > discovery_time[node]`**, then the edge `(node, neighbor)` is a bottleneck bottleneck with no backup route. **It is a critical connection.**

---

## 🚀 Optimized C++ Code

```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void dfs(int node, int parent, int &time,
             const vector<vector<int>>& adj,
             vector<int>& discover_time,
             vector<int>& low,
             vector<vector<int>>& critical_edges) { // Passed by reference to avoid copying
        
        // Initialize discovery time and low value to the current time counter
        discover_time[node] = low[node] = ++time;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue; // Skip backtracking directly to the parent

            if (discover_time[neighbor] == -1) {
                // Scenario A: Neighbor is not visited yet (Forward Tree Edge)
                dfs(neighbor, node, time, adj, discover_time, low, critical_edges);

                // On return from recursion, update current node's low value
                low[node] = min(low[node], low[neighbor]);

                // Evaluate Tarjan's Bridge Condition
                if (low[neighbor] > discover_time[node]) {
                    critical_edges.push_back({node, neighbor});
                }
            } 
            else {
                // Scenario B: Neighbor is already visited (Back-Edge/Shortcut Cycle found)
                low[node] = min(low[node], discover_time[neighbor]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // 1. Construct adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // 2. Setup tracking structures
        vector<int> low(n, -1);
        vector<int> discover_time(n, -1);
        vector<vector<int>> critical_edges;

        int time = 0;
        
        // 3. Initiate DFS from node 0 (Assumes entire network is initially connected)
        dfs(0, -1, time, adj, discover_time, low, critical_edges);
        
        return critical_edges;
    }
};

📊 Complexity AnalysisTime Complexity: $\mathcal{O}(V + E)$Every vertex $V$ and connection $E$ is examined exactly once during the recursive DFS traversal.Space Complexity: $\mathcal{O}(V + E)$Required to store the adjacency list structure, tracking arrays (discover_time, low), and the implicit recursion execution stack frames.📚 Practice Problems (LeetCode)If you want to master this concept and its variations (like finding Articulation Points or Strongly Connected Components), give these problems a try:LC 1192. Critical Connections in a Network (Hard)Type: Bridges / Cut-EdgesFocus: The absolute textbook problem for finding bridges using Tarjan's technique (this problem's exact solution).LC 1568. Minimum Number of Days to Disconnect Island (Hard)Type: Articulation Points / Cut-VerticesFocus: Uses a similar strategy to find if removing a single node splits the graph component. The condition changes slightly to low[neighbor] >= discover_time[node].LC 2360. Longest Cycle in a Graph (Hard)Type: Strongly Connected Components (SCC) / Cycle DetectionFocus: Leverages discovery timestamps to immediately calculate cycle lengths the instant a back-edge points back to an active path ancestor.LC 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree (Hard)Type: MST + Bridge Finder OptimizationFocus: Often solved with Kruskal's algorithm, but finding bridges inside equal-weight edge subsets can be highly optimized using Tarjan's approach.