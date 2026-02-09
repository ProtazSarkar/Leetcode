class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        if (n == 0) return 0;

        vector<pair<int, char>> blocks;
        int running_count = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && s[i] == s[i - 1]) {
                running_count++;
            } else {
                blocks.push_back({running_count, s[i - 1]});
                running_count = 1;
            }
        }

        int m = blocks.size();
        // dp[i] = min deletions for the first i blocks
        vector<int> dp(m + 1, 0);
        int b_count = 0; // Total 'b's seen so far

        for (int i = 1; i <= m; i++) {
            int count = blocks[i - 1].first;
            char type = blocks[i - 1].second;

            if (type == 'b') {
                // 'b' blocks don't cause deletions for the current state
                dp[i] = dp[i - 1];
                b_count += count;
            } else {
                // 'a' block detected! Decision time:
                // Option 1: Delete this block of 'a's -> dp[i-1] + count
                // Option 2: Keep 'a's, delete all previous 'b's -> b_count
                dp[i] = min(dp[i - 1] + count, b_count);
            }
        }

        return dp[m];
    }
};
