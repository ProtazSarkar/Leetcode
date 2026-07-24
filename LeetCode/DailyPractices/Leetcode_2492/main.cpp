#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Step 1: Build the adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Step 2: BFS to find the minimum edge weight in the connected component of node 1
        int min_score = INT_MAX;
        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                // Track the minimum edge weight seen so far in this component
                min_score = min(min_score, w);

                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return min_score;
    }
};