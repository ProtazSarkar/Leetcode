#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> prefix_digit_sum(n);
        vector<long long> prefix_num(n);
        vector<int> non_zero_count(n, 0);
        
        // Precompute powers of 10 modulo MOD
        vector<long long> power10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        // Initialize base case
        int first_digit = s[0] - '0';
        prefix_digit_sum[0] = first_digit;
        prefix_num[0] = first_digit; 
        non_zero_count[0] = (first_digit != 0) ? 1 : 0;

        // Build prefix states
        for(int i = 1; i < n; i++){
            int d = s[i] - '0';
            prefix_digit_sum[i] = prefix_digit_sum[i - 1] + d;
            
            if(d == 0){
                prefix_num[i] = prefix_num[i - 1];
                non_zero_count[i] = non_zero_count[i - 1];
            } else {
                prefix_num[i] = ((prefix_num[i - 1] * 10) % MOD + d) % MOD;
                non_zero_count[i] = non_zero_count[i - 1] + 1;
            }
        }

        vector<int> ans;
        for(auto& q : queries){
            int l = q[0];
            int r = q[1];

            long long x = 0;
            long long sum = 0;

            if(l == 0){
                x = prefix_num[r];
                sum = prefix_digit_sum[r];
            } else {
                // Number of non-zero digits in the current substring window
                int non_zeros_in_window = non_zero_count[r] - non_zero_count[l - 1];
                
                // Shift the prefix left by exactly how many non-zero elements are in the window
                long long shift_prefix = (prefix_num[l - 1] * power10[non_zeros_in_window]) % MOD;
                
                // Keep modular subtraction safe from negative numbers
                x = (prefix_num[r] - shift_prefix + MOD) % MOD;
                sum = prefix_digit_sum[r] - prefix_digit_sum[l - 1];
            }

            // Perform multiplication using 64-bit precision to prevent overflow
            long long result = (x * (sum % MOD)) % MOD;
            ans.push_back(result);
        }

        return ans;
    }
};