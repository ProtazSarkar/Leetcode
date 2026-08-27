#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    std::vector<int> memo;

    bool canForm(int mask, int currSum, int target, int n, const std::vector<int>& matchsticks) {
        // Base Case: All matchsticks have been placed
        if (mask == (1 << n) - 1) {
            return true;
        }

        // Return cached result if state already visited
        if (memo[mask] != -1) {
            return memo[mask];
        }

        // Try placing every unused matchstick
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) { // Matchstick i is not used yet
                if (currSum + matchsticks[i] <= target) {
                    // Reset currSum to 0 when a side completes
                    int nextSum = (currSum + matchsticks[i] == target) ? 0 : currSum + matchsticks[i];
                    
                    if (canForm(mask | (1 << i), nextSum, target, n, matchsticks)) {
                        return memo[mask] = true;
                    }
                }
            }
        }

        return memo[mask] = false;
    }

public:
    bool makesquare(std::vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;

        int totalSum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalSum % 4 != 0) return false;

        int target = totalSum / 4;

        // Sort descending to fail early on invalid paths
        std::sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks[0] > target) return false;

        // Memo array initialized to -1 (unvisited)
        memo.assign(1 << n, -1);

        return canForm(0, 0, target, n, matchsticks);
    }
};