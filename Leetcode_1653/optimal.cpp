class Solution {
    // Memoization table: memo[block_index]
    vector<int> memo;

    int solve(vector<pair<int, char>>& blocks, int i, int b_count) {
        // Base case: no more blocks to process
        if (i == blocks.size()) return 0;

        if (blocks[i].second == 'b') {
            // It's a 'b' block: no conflict yet. 
            // Add these 'b's to our running count and move on.
            return solve(blocks, i + 1, b_count + blocks[i].first);
        } else {
            // It's an 'a' block: CONFLICT! 
            // Option 1: Delete this block of 'a's
            int deleteA = blocks[i].first + solve(blocks, i + 1, b_count);
            
            // Option 2: Keep this block of 'a's (Must delete all previous 'b's)
            int deletePrevB = b_count + solve(blocks, i + 1, 0); 

            return min(deleteA, deletePrevB);
        }
    }

public:
    int minimumDeletions(string s) {
        vector<pair<int, char>> blocks;
        int n = s.length();
        if (n == 0) return 0;

        // Grouping into blocks
        int count = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && s[i] == s[i - 1]) count++;
            else {
                blocks.push_back({count, s[i - 1]});
                count = 1;
            }
        }
        return solve(blocks, 0, 0);
    }
};
