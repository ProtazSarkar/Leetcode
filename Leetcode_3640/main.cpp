class Solution {
    int n;
    const long long INF = 1e15; // Using a cleaner large value
    vector<vector<long long>> dp;

    long long solve(vector<int>& a, int i, int trend) {
        if (i == n) {
            // Only valid if we finished the final increasing part (trend 4)
            return (trend == 4 ? 0 : -INF);
        }

        if (dp[i][trend] != -1) return dp[i][trend];

        long long ans = -INF;

        // State 0: Haven't started the subarray yet
        if (trend == 0) {
            // Option A: Skip this element and stay in state 0
            ans = max(ans, solve(a, i + 1, 0));
            // Option B: Start the first increasing leg here
            // (Note: l < p, so we need at least one more element after this)
            long long next = solve(a, i + 1, 1);
            if (next != -INF) ans = max(ans, a[i] + next);
        }

        // State 1: Strictly Increasing (l to p)
        else if (trend == 1) {
            if (a[i] > a[i-1]) {
                // Stay in state 1 (keep increasing)
                long long stay = solve(a, i + 1, 1);
                if (stay != -INF) ans = max(ans, a[i] + stay);
                
                // Transition to state 2 (reached peak p, now starting decrease)
                long long move = solve(a, i + 1, 2);
                if (move != -INF) ans = max(ans, a[i] + move);
            }
        }

        // State 2: Strictly Decreasing (p to q)
        else if (trend == 2) {
            if (a[i] < a[i-1]) {
                // Stay in state 2 (keep decreasing)
                long long stay = solve(a, i + 1, 2);
                if (stay != -INF) ans = max(ans, a[i] + stay);
                
                // Transition to state 3 (reached valley q, now starting second increase)
                long long move = solve(a, i + 1, 3);
                if (move != -INF) ans = max(ans, a[i] + move);
            }
        }

        // State 3: Strictly Increasing (q to r)
        else if (trend == 3) {
            if (a[i] > a[i-1]) {
                // Stay in state 3 (keep increasing)
                long long stay = solve(a, i + 1, 3);
                if (stay != -INF) ans = max(ans, a[i] + stay);
                
                // Transition to state 4 (Completed! We can stop here)
                ans = max(ans, (long long)a[i]);
            }
        }

        return dp[i][trend] = ans;
    }

public:
    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        // Initializing with -1 to differentiate between "uncomputed" and "impossible sum"
        dp.assign(n, vector<long long>(5, -1));
        long long result = solve(nums, 0, 0);
        return (result < -1e14 ? -1 : result);
    }
};
