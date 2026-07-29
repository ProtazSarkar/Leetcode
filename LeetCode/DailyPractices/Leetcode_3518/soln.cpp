#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    long long combination(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n / k) k = n - k;
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            // Prevent overflow during multiplication
            if (res > 2e18 / (n - i + 1)) return 2e18;
            res = res * (n - i + 1) / i;
        }
        return res;
    }

    long long count_arrangements(vector<int>& freq, int n) {
        long long res = 1;
        int rem = n;
        for (int f : freq) {
            if (f > 0) {
                long long c = combination(rem, f);
                if (res > 2e18 / c) return 2e18;
                res *= c;
                rem -= f;
            }
        }
        return res;
    }

    string kth_lexicographical(vector<int>& freq, int n, long long k) {
        if (n == 0) return "";
        string ans = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                freq[i]--;
                long long ways = count_arrangements(freq, n - 1);
                if (k <= ways) {
                    ans.push_back('a' + i);
                    ans += kth_lexicographical(freq, n - 1, k);
                    return ans;
                } else {
                    k -= ways;
                    freq[i]++;
                }
            }
        }
        return "";
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> total_freq(26, 0);
        for (char c : s) {
            total_freq[c - 'a']++;
        }

        int odd_count = 0;
        char mid_char = '\0';
        for (int i = 0; i < 26; i++) {
            if (total_freq[i] % 2 != 0) {
                odd_count++;
                mid_char = (char)('a' + i);
            }
        }

        if (odd_count > (n % 2 == 1 ? 1 : 0)) return "";

        vector<int> half_freq(26, 0);
        for (int i = 0; i < 26; i++) {
            half_freq[i] = total_freq[i] / 2;
        }

        int half_len = n / 2;
        long long total = count_arrangements(half_freq, half_len);
        if (total < k) return "";

        string left_half = kth_lexicographical(half_freq, half_len, k);
        string ans = left_half;
        if (n % 2 == 1) {
            ans.push_back(mid_char);
        }
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        ans += right_half;

        return ans;
    }
};