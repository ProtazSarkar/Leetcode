class Solution {
    int dp[1001][1001][2];
    int MOD = 1e9 + 7;

    int solve(int i, int k, bool drawing, int n) {
        if (k == 0) return 1;
        if (i == n) return 0;
        if (dp[i][k][drawing] != -1) return dp[i][k][drawing];

        long long ans = 0;
        if (drawing) {
            // Option 1: Keep extending the current segment to the next point (i + 1)
            // Option 2: Stop the current segment at point i, decrease k, and we can immediately start a new one here
            ans = (solve(i + 1, k, true, n) + solve(i, k - 1, false, n)) % MOD;
        } else {
            // Option 1: Skip point i entirely
            // Option 2: Start a new segment at point i
            ans = (solve(i + 1, k, false, n) + solve(i + 1, k, true, n)) % MOD;
        }

        return dp[i][k][drawing] = ans;
    }

public:
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, k, false, n);
    }
};