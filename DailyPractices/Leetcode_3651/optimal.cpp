class Solution {
    int INF = 1e9;

    struct Node {
        int cost;
        int x, y, t;
    };

    struct cmp {
        bool operator()(const Node& a, const Node& b) {
            return a.cost > b.cost; // min heap
        }
    };

public:
    int minCost(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, INF))
        );

        priority_queue<Node, vector<Node>, cmp> pq;

        // start from destination
        dp[n-1][m-1][0] = 0;
        pq.push({0, n-1, m-1, 0});

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            int i = curr.x;
            int j = curr.y;
            int t = curr.t;
            int cost = curr.cost;

            if (i == 0 && j == 0)
                return cost;

            if (cost > dp[i][j][t]) continue;

            // move up
            if (i - 1 >= 0) {
                int newCost = cost + grid[i-1][j];
                if (newCost < dp[i-1][j][t]) {
                    dp[i-1][j][t] = newCost;
                    pq.push({newCost, i-1, j, t});
                }
            }

            // move left
            if (j - 1 >= 0) {
                int newCost = cost + grid[i][j-1];
                if (newCost < dp[i][j-1][t]) {
                    dp[i][j-1][t] = newCost;
                    pq.push({newCost, i, j-1, t});
                }
            }

            // teleport backward
            if (t < k) {
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (grid[x][y] <= grid[i][j]) {
                            if (cost < dp[x][y][t+1]) {
                                dp[x][y][t+1] = cost;
                                pq.push({cost, x, y, t+1});
                            }
                        }
                    }
                }
            }
        }

        return -1;
    }
};