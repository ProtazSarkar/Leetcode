class Solution {
    const int INF = 1e9;
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j][t]
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, INF))
        );

        // base case
        for (int t = 0; t <= k; t++)
            dp[n - 1][m - 1][t] = 0;

        // bottom-up filling
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int t = 0; t <= k; t++) {

                    if (i == n - 1 && j == m - 1) continue;

                    // normal move: down
                    if (i + 1 < n) {
                        dp[i][j][t] = min(
                            dp[i][j][t],
                            grid[i + 1][j] + dp[i + 1][j][t]
                        );
                    }

                    // normal move: right
                    if (j + 1 < m) {
                        dp[i][j][t] = min(
                            dp[i][j][t],
                            grid[i][j + 1] + dp[i][j + 1][t]
                        );
                    }

                    // teleport
                    if (t > 0) {
                        for (int x = 0; x < n; x++) {
                            for (int y = 0; y < m; y++) {
                                if (grid[x][y] <= grid[i][j]) {
                                    dp[i][j][t] = min(
                                        dp[i][j][t],
                                        dp[x][y][t - 1]
                                    );
                                }
                            }
                        }
                    }
                }
            }
        }

        return dp[0][0][k];
    }
};