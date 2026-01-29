class Solution {
    const int INF = 1e9;

public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        // dist[i][j] = min cost to convert (i+'a') -> (j+'a')
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // self conversion cost = 0
        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        // initialize edges
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j],
                                          dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;

        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (dist[s][t] == INF) return -1;
            totalCost += dist[s][t];
        }

        return totalCost;
    }
};