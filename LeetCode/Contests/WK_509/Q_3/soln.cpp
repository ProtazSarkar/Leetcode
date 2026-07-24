#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int divisibleGame(vector<int>& nums) {
        int n = nums.size();

        // Generate primes up to 1000 (sqrt(1e6))
        vector<int> smallPrimes;
        vector<bool> isPrime(1001, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= 1000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 1000; j += i)
                    isPrime[j] = false;
            }
        }

        for (int i = 2; i <= 1000; i++)
            if (isPrime[i]) smallPrimes.push_back(i);

        // Collect all distinct prime factors appearing in nums
        unordered_set<int> candidates;
        candidates.insert(2); // Needed if every element is 1

        for (int x : nums) {
            int temp = x;

            for (int p : smallPrimes) {
                if (1LL * p * p > temp) break;

                if (temp % p == 0) {
                    candidates.insert(p);
                    while (temp % p == 0)
                        temp /= p;
                }
            }

            if (temp > 1)
                candidates.insert(temp);
        }

        long long bestScore = LLONG_MIN;
        int bestK = INT_MAX;

        // Try every candidate prime
        for (int k : candidates) {

            long long curr = (nums[0] % k == 0) ? nums[0] : -1LL * nums[0];
            long long mx = curr;

            for (int i = 1; i < n; i++) {
                long long val = (nums[i] % k == 0) ? nums[i] : -1LL * nums[i];

                curr = max(val, curr + val);   // Kadane
                mx = max(mx, curr);
            }

            if (mx > bestScore || (mx == bestScore && k < bestK)) {
                bestScore = mx;
                bestK = k;
            }
        }

        long long ans = ((bestScore % MOD + MOD) % MOD);
        ans = (ans * bestK) % MOD;

        return (int)ans;
    }
};