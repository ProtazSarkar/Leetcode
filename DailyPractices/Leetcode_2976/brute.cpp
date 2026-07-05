class Solution {
    const int INF = 1e9;

    int dfs(char s, char t,
            vector<vector<pair<char,int>>>& graph,
            vector<int>& vis) {

        if (s == t) return 0;

        int u = s - 'a';
        vis[u] = 1;

        int ans = INF;

        for (auto &adj : graph[u]) {
            char v = adj.first;
            int w = adj.second;
            int idx = v - 'a';

            if (!vis[idx]) {
                int sub = dfs(v, t, graph, vis);
                if (sub != INF) {
                    ans = min(ans, w + sub);
                }
            }
        }

        vis[u] = 0; // backtrack
        return ans;
    }

public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        // graph initialization
        vector<vector<pair<char,int>>> graph(26);

        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            graph[u].push_back({changed[i], cost[i]});
        }

        long long totalCost = 0;

        for (int i = 0; i < source.size(); i++) {
            vector<int> vis(26, 0);
            int cur = dfs(source[i], target[i], graph, vis);

            if (cur == INF) return -1;  // impossible transformation
            totalCost += cur;
        }

        return totalCost;
    }
};