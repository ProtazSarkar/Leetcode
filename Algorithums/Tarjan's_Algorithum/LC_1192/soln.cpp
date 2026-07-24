#include <vector>
#include <algorithm>

class Solution {
private:
    void dfs(int node, int parent, int& time, 
             const std::vector<std::vector<int>>& adj, 
             std::vector<int>& disc, std::vector<int>& low, 
             std::vector<std::vector<int>>& criticalEdges) {
        
        disc[node] = low[node] = ++time;
        
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue; // Skip going back to the direct parent
            
            if (disc[neighbor] == -1) {
                // Neighbor has not been visited yet
                dfs(neighbor, node, time, adj, disc, low, criticalEdges);
                
                // Upon return, update the low value of the current node
                low[node] = std::min(low[node], low[neighbor]);
                
                // Check the bridge condition
                if (low[neighbor] > disc[node]) {
                    criticalEdges.push_back({node, neighbor});
                }
            } else {
                // Back-edge found: update the low value with the discovery time of the neighbor
                low[node] = std::min(low[node], disc[neighbor]);
            }
        }
    }

public:
    std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections) {
        // 1. Build the adjacency list
        std::vector<std::vector<int>> adj(n);
        for (const auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        
        // 2. Initialize tracking vectors
        std::vector<int> disc(n, -1);
        std::vector<int> low(n, -1);
        std::vector<std::vector<int>> criticalEdges;
        
        int time = 0;
        
        // 3. Start DFS from node 0 (since the entire network is connected)
        dfs(0, -1, time, adj, disc, low, criticalEdges);
        
        return criticalEdges;
    }
};