class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case: Row 1 is always "0"
        if (n == 1 && k == 1) return 0;

        int mid = 1 << (n - 2); // Midpoint of current row (2^(n-2))

        if (k <= mid) {
            // First half: exact same as parent in row n-1
            return kthGrammar(n - 1, k);
        } else {
            // Second half: inverted value of corresponding element in first half
            return !kthGrammar(n - 1, k - mid);
        }
    }
};
