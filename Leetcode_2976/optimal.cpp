class Solution {
    const int INF = 1e9;

    int get_minCost(char s, char t,
                    vector<vector<pair<char,int>>>& graph) {

        vector<int> dist(26, INF);
        dist[s - 'a'] = 0;

        priority_queue<
            pair<int,char>,
            vector<pair<int,char>>,
            greater<>
        > pq;

        pq.push({0, s});

        while (!pq.empty()) {
            auto [cost, c] = pq.top();
            pq.pop();

            int u = c - 'a';
            if (cost > dist[u]) continue;

            for (auto &[v, w] : graph[u]) {
                int vidx = v - 'a';
                if (dist[vidx] > dist[u] + w) {
                    dist[vidx] = dist[u] + w;
                    pq.push({dist[vidx], v});
                }
            }
        }

        return dist[t - 'a'];
    }

public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        vector<vector<pair<char,int>>> graph(26);

        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            graph[u].push_back({changed[i], cost[i]});
        }

        long long totalCost = 0;

        for (int i = 0; i < source.size(); i++) {
            int cur = get_minCost(source[i], target[i], graph);
            if (cur == INF) return -1;
            totalCost += cur;
        }

        return totalCost;
    }
};