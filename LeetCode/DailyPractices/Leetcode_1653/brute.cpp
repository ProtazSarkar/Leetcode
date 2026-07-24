class Solution {
public:
    int INF = 1e9;

    bool is_balance(vector<char>& arr) {
        bool foundB = false;
        for (char c : arr) {
            if (c == 'b') foundB = true;
            if (c == 'a' && foundB) return false; // 'a' found after a 'b'
        }
        return true;
    }

    // recursive dp (pure brute force)
    int solve(vector<char> arr, int i) {
        // Base case: if we checked everything or it's already balanced
        if (is_balance(arr)) return 0;
        if (i >= arr.size()) return INF;

        // Choice 1: Skip deleting this character (move to next)
        int take = solve(arr, i + 1);

        // Choice 2: Delete this character and increment cost
        vector<char> next_arr = arr;
        next_arr.erase(next_arr.begin() + i);
        int skip = 1 + solve(next_arr, i);

        return min(take, skip);
    }

    int minimumDeletions(string s) {
        vector<char> arr(s.begin(), s.end());
        return solve(arr, 0);
    }
};
