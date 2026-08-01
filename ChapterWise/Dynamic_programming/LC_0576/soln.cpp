class Solution {
    long long memo[55][55][55];
    int MOD = 1e9 + 7;

    long long solve(int r, int c, int moves, int m, int n) {
        // Base Case 1: If the ball moves out of the boundary, it's 1 valid path
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return 1;
        }
        // Base Case 2: If we ran out of moves and are still inside, 0 paths
        if (moves == 0) {
            return 0;
        }
        if (memo[r][c][moves] != -1) {
            return memo[r][c][moves];
        }

        long long paths = 0;
        // Try all 4 directions
        paths = (paths + solve(r + 1, c, moves - 1, m, n)) % MOD;
        paths = (paths + solve(r - 1, c, moves - 1, m, n)) % MOD;
        paths = (paths + solve(r, c + 1, moves - 1, m, n)) % MOD;
        paths = (paths + solve(r, c - 1, moves - 1, m, n)) % MOD;

        return memo[r][c][moves] = paths;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo, -1, sizeof(memo));
        return solve(startRow, startColumn, maxMove, m, n);
    }
};