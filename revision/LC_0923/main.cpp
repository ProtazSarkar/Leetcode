#include <vector>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int MOD = 1e9 + 7;

        // Count frequency of each number (0 <= arr[i] <= 100)
        vector<long long> count(101, 0);
        for (int x : arr) {
            count[x]++;
        }

        long long ans = 0;

        for (int i = 0; i <= 100; i++) {
            if (count[i] == 0) continue;

            for (int j = i; j <= 100; j++) {
                if (count[j] == 0) continue;

                int k = target - i - j;
                
                // Keep k >= j to avoid duplicate tuple counting and out of bounds
                if (k < j || k > 100 || count[k] == 0) {
                    continue;
                }

                // Case 1: All three numbers are equal (i == j == k)
                if (i == j && j == k) {
                    ans += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
                }
                // Case 2: First two are equal (i == j < k)
                else if (i == j && j < k) {
                    ans += (count[i] * (count[i] - 1) / 2) * count[k];
                }
                // Case 3: Last two are equal (i < j == k)
                else if (i < j && j == k) {
                    ans += count[i] * (count[j] * (count[j] - 1) / 2);
                }
                // Case 4: All three numbers are distinct (i < j < k)
                else if (i < j && j < k) {
                    ans += count[i] * count[j] * count[k];
                }

                ans %= MOD;
            }
        }

        return ans;
    }
};