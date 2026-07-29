#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    vector<long long> factorials;
    const long long INF = 1e18;
    
    void __init__(int n){
        if (n <= 0) return;
        factorials.assign(n + 1, 1);
        factorials[0] = 1;
        factorials[1] = 1;

        for(int i = 2; i <= n; i++){
            if (factorials[i - 1] > INF / i) {
                factorials[i] = INF;
            } else {
                factorials[i] = i * factorials[i - 1];
            }
        }
    }

    long long calculate_total_permutation(vector<int>& freq, int n){
        if (n <= 0) return 1;
        long long total_permutation = factorials[n];
        for(int f : freq){
            if (f > 0) {
                total_permutation /= factorials[f];
            }
        }
        return total_permutation;
    }

    string kth_lexicographical(vector<int>& freq, int n, int k){
        if (n <= 0) return "";
        
        vector<char> unique;
        unique.reserve(26);
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                unique.push_back('a' + i);
            }
        }

        long long total_permutation = calculate_total_permutation(freq, n);
        if(total_permutation < k) return "";

        string ans = "";

        for(char c : unique){
            int idx = c - 'a';
            freq[idx]--;
            long long ways = calculate_total_permutation(freq, n - 1);
            
            if(k <= ways){
                ans.push_back(c);
                ans += kth_lexicographical(freq, n - 1, k);
                return ans;
            } else {
                k -= ways;
                freq[idx]++;
            }
        }
        return "";
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        
        // Handle edge case for single character or empty string
        if (n == 1) {
            return (k == 1) ? s : "";
        }

        int half_n = n / 2;
        __init__(half_n);

        vector<int> total_freq(26, 0);
        for(char c : s){
            total_freq[c - 'a']++;
        }

        vector<int> half_freq(26, 0);
        char mid_char = '\0';
        for(int i = 0; i < 26; i++){
            half_freq[i] = total_freq[i] / 2;
            if(total_freq[i] % 2 != 0){
                mid_char = (char)('a' + i);
            }
        }

        string lower_half = kth_lexicographical(half_freq, half_n, k);
        if(lower_half == "" && k > 1) return "";

        string ans = lower_half;
        if(n & 1){
            ans.push_back(mid_char);
        }
        string right_half = lower_half;
        reverse(right_half.begin(), right_half.end());
        ans += right_half;
        
        return ans;
    }
};