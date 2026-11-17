#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    const int INF = 1e9 + 7;

    vector<int> getDivisors(int n) {
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    int palindromeCost(const string& s) {
        int left = 0, right = (int)s.size() - 1;
        int cost = 0;
        while (left < right) {
            if (s[left] != s[right]) {
                cost++;
            }
            left++;
            right--;
        }
        return cost;
    }

    int semiPalindromeCost(const string& s) {
        int n = (int)s.size();
        if (n < 2) return INF;

        vector<int> divs = getDivisors(n);
        int ret = INF;

        for (int d : divs) {
            int pCost = 0;
            for (int i = 0; i < d; i++) {
                string g;
                for (int j = i; j < n; j += d) {
                    g += s[j];
                }
                pCost += palindromeCost(g);
            }
            ret = min(ret, pCost);
        }

        return ret;
    }

    int solve(int start, int partsLeft, const string& s, vector<vector<int>>& memo) {
        int n = (int)s.size();
        // Need at least 2 characters per remaining part
        if (n - start < 2 * partsLeft) return INF;

        int& res = memo[start][partsLeft];
        if (res != -1) return res;

        if (partsLeft == 1) {
            return res = semiPalindromeCost(s.substr(start, n - start));
        }

        int ans = INF;
        // Current part ends at `end` (length >= 2), leaving at least 2*(partsLeft - 1) chars after `end`
        int maxEnd = n - 1 - 2 * (partsLeft - 1);
        for (int end = start + 1; end <= maxEnd; end++) {
            int curCost = semiPalindromeCost(s.substr(start, end - start + 1));
            if (curCost < INF) {
                int nextCost = solve(end + 1, partsLeft - 1, s, memo);
                if (nextCost < INF) {
                    ans = min(ans, curCost + nextCost);
                }
            }
        }

        return res = ans;
    }

public:
    int minimumChanges(string s, int k) {
        int n = (int)s.size();
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));
        return solve(0, k, s, memo);
    }
};