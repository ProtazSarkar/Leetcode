class Solution {
    unordered_map<int, int> numtoidx;
    unordered_map<long long, int> memo;

    int solve(int i, int j, vector<int>& arr) {
        long long key = (long long)i << 32 | j;
        if (memo.count(key)) {
            return memo[key];
        }

        int target = arr[j] - arr[i];
        if (target < arr[i] && numtoidx.count(target)) {
            int k = numtoidx[target];
            return memo[key] = solve(k, i, arr) + 1;
        }
        return memo[key] = 2;
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return 0;

        // Clear previous test case data
        numtoidx.clear();
        memo.clear();

        for (int i = 0; i < n; i++) { // Fixed 'i==' to 'i='
            numtoidx[arr[i]] = i;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, solve(i, j, arr)); // Fixed 'nums' to 'arr'
            }
        }

        return ans >= 3 ? ans : 0; // Added safety check to return 0 if max length is less than 3
    }
};