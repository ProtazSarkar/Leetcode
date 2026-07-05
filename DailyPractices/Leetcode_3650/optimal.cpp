#include <bits/stdc++.h>
using namespace std;

class Solution {
    int INF = 1e9;
public:
    int minCost(int n, vector<vector<int>>& edges) {

        // adjacency list
        vector<vector<pair<int,int>>> graph(n);

        // build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }

        vector<int> dist(n, INF);
        dist[0] = 0;

        // min-heap (cost, node)
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (auto [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == INF ? -1 : dist[n - 1];
    }
};