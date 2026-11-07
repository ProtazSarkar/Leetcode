#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long MOD = 1e9 + 7;
        vector<long long> count(101, 0);

        // Count frequency of each number
        for (int x : arr) {
            count[x]++;
        }

        long long ans = 0;

        // Iterate through all possible values for i and j (from 0 to 100)
        for (int i = 0; i <= 100; i++) {
            if (count[i] == 0) continue;

            for (int j = i; j <= 100; j++) {
                if (count[j] == 0) continue;

                int k = target - i - j;
                if (k < 0 || k > 100) continue;
                if (count[k] == 0) continue;

                // Case 1: All three numbers are the same (i == j == k)
                if (i == j && j == k) {
                    ans = (ans + count[i] * (count[i] - 1) * (count[i] - 2) / 6) % MOD;
                }
                // Case 2: i and j are the same, but k is different (i == j < k)
                else if (i == j && j < k) {
                    ans = (ans + (count[i] * (count[i] - 1) / 2) * count[k]) % MOD;
                }
                // Case 3: i < j and j == k (i < j == k)
                else if (i < j && j == k) {
                    ans = (ans + count[i] * (count[j] * (count[j] - 1) / 2)) % MOD;
                }
                // Case 4: All three numbers are distinct (i < j < k)
                else if (i < j && j < k) {
                    ans = (ans + count[i] * count[j] * count[k]) % MOD;
                }
            }
        }

        return ans;
    }
};