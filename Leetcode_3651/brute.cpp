#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int n, m;
    const int INF = 1e9;

    // dp[i][j][k] = minimum cost to reach destination from (i,j) with k teleports left
    vector<vector<vector<int>>> dp;

    int dfs(int i, int j, int k, vector<vector<int>>& grid) {
        // out of bounds
        if (i < 0 || j < 0 || i >= n || j >= m)
            return INF;

        // destination: no move needed, cost = 0
        if (i == n - 1 && j == m - 1)
            return 0;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int ans = INF;

        // ---- normal moves ----
        if (i + 1 < n)
            ans = min(ans,
                grid[i + 1][j] + dfs(i + 1, j, k, grid));

        if (j + 1 < m)
            ans = min(ans,
                grid[i][j + 1] + dfs(i, j + 1, k, grid));

        // ---- teleport moves ----
        if (k > 0) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (grid[x][y] <= grid[i][j]) {
                        ans = min(ans,
                            dfs(x, y, k - 1, grid));
                    }
                }
            }
        }

        return dp[i][j][k] = ans;
    }

public:
    int minCost(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        return dfs(0, 0, k, grid);
    }
};