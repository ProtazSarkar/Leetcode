class Solution {
    // A segment tree where each node holds an array of 26 ints
    // Using a 2D array to keep it close to your pointer/array style
    int segTree[8001][26]; 

    void buildSegTree(int i, string &s, int l, int h) {
        if (l == h) {
            for(int j = 0; j < 26; j++) segTree[i][j] = 0;
            segTree[i][s[l] - 'a'] = 1; // Mark the character present
            return;
        }
        int mid = (l + h) / 2;
        buildSegTree(2 * i + 1, s, l, mid);
        buildSegTree(2 * i + 2, s, mid + 1, h);

        // Merge step: Sum up counts from left and right children
        for (int j = 0; j < 26; j++) {
            segTree[i][j] = segTree[2 * i + 1][j] + segTree[2 * i + 2][j];
        }
    }

    // This is the "Searching Part" you were stuck on!
    void query(int i, int l, int h, int qL, int qR, int* result) {
        if (qL <= l && h <= qR) { // Node range is fully inside query range
            for (int j = 0; j < 26; j++) result[j] += segTree[i][j];
            return;
        }
        if (h < qL || l > qR) return; // Completely outside

        int mid = (l + h) / 2;
        query(2 * i + 1, l, mid, qL, qR, result);
        query(2 * i + 2, mid + 1, h, qL, qR, result);
    }

    bool is_balanced(int n, int l, int h) {
        int counts[26] = {0};
        query(0, 0, n - 1, l, h, counts);

        int static_freq = -1;
        for (int j = 0; j < 26; j++) {
            if (counts[j] > 0) {
                if (static_freq == -1) static_freq = counts[j];
                else if (counts[j] != static_freq) return false;
            }
        }
        return static_freq != -1;
    }

public:
    int longestBalanced(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        // Initialize tree to zero and build it
        buildSegTree(0, s, 0, n - 1);

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (is_balanced(n, i, j)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
