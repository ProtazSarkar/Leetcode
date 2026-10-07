class Solution {
    int cal_dis(int x, int y) {
        int dis = abs(x - y);
        return min(10 - dis, dis);
    }
public:
    int minRotations(int n, string s) {
        vector<int> digits(n);
        for (int i = 0; i < n; i++) {
            digits[i] = s[i] - '0';
        }

        // prefix[i] = normal cost to dial s[0...i-1] starting from 0
        vector<int> prefix(n + 1, 0);
        prefix[1] = cal_dis(0, digits[0]);
        for (int i = 1; i < n; i++) {
            prefix[i + 1] = prefix[i] + cal_dis(digits[i - 1], digits[i]);
        }

        int ans = prefix[n];

        // backward_cost[i] = cost of traversing s[n-1] down to s[i] in reverse order
        vector<int> backward(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            backward[i] = backward[i + 1] + cal_dis(digits[i + 1], digits[i]);
        }

        // Try reversing suffix starting at index k (from 0 to n-1)
        for (int k = 0; k < n; k++) {
            int from = (k > 0) ? digits[k - 1] : 0;
            int last = digits[n - 1];
            
            // Cost = (prefix up to k) + (transition from prefix-end to s[n-1]) + (reversed suffix from n-1 down to k)
            int current_reversal_cost = prefix[k] + cal_dis(from, last) + backward[k];
            ans = min(ans, current_reversal_cost);
        }

        return ans;
    }
};