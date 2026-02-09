class Solution {
    int INF = 1e9;

    // A string is balanced if it looks like: [some 'a's], [some 'b's]
    // Or just [all 'a's] or [all 'b's]
    bool is_balance(vector<pair<int, char>>& counts) {
        if (counts.empty()) return true;
        
        bool foundB = false;
        for (auto& p : counts) {
            if (p.second == 'b') foundB = true;
            if (p.second == 'a' && foundB) return false;
        }
        return true;
    }

    int solve(vector<pair<int, char>> counts, int i) {
        if (is_balance(counts)) return 0;
        if (i >= counts.size()) return INF;

        // Choice 1: Keep this block as it is
        int keep = solve(counts, i + 1);

        // Choice 2: Remove this entire block
        int cost = counts[i].first;
        vector<pair<int, char>> next_counts = counts;
        next_counts.erase(next_counts.begin() + i);
        
        // Optional logic: After removing, we could merge neighbors if they are same char
        // But for pure brute force, simple removal is enough
        int remove = cost + solve(next_counts, i);

        return min(keep, remove);
    }

public:
    int minimumDeletions(string s) {
        if (s.empty()) return 0;

        vector<pair<int, char>> counts;
        int n = s.length();
        
        // Grouping logic: "aaabbba" -> {3,'a'}, {3,'b'}, {1,'a'}
        int running_count = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && s[i] == s[i - 1]) {
                running_count++;
            } else {
                counts.push_back({running_count, s[i - 1]});
                running_count = 1;
            }
        }

        return solve(counts, 0);
    }
};
