#include <vector>
#include <string>

using namespace std;

class Solution {
    int M, N, K;
    vector<string> grid;

    // Helper to count paths from (0,0) to (M-1, N-1)
    long long countPaths(const vector<string>& g) {
        if (g[0][0] == '#' || g[M - 1][N - 1] == '#') return 0;
        vector<vector<long long>> dp(M, vector<long long>(N, 0));
        dp[0][0] = 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (g[i][j] == '#') continue;
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[M - 1][N - 1];
    }

    bool backtrack(int r, int c) {
        if (r == M) {
            return countPaths(grid) == K;
        }

        int nextR = (c == N - 1) ? r + 1 : r;
        int nextC = (c == N - 1) ? 0 : c + 1;

        // Try placing '.'
        grid[r][c] = '.';
        if (backtrack(nextR, nextC)) return true;

        // Try placing '#'
        grid[r][c] = '#';
        if (backtrack(nextR, nextC)) return true;

        return false;
    }

public:
    vector<string> createGrid(int m, int n, int k) {
        this->M = m;
        this->N = n;
        this->K = k;
        grid = vector<string>(m, string(n, '#'));

        if (backtrack(0, 0)) return grid;
        return {}; // Return empty if no grid found
    }
};