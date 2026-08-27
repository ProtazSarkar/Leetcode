#include <unordered_map>
using namespace std;

class Solution {
    std::unordered_map<int, bool> memo;

    bool canwin(int usebit, int currtotal, int maxchoose, int dest) {
        if (memo.count(usebit)) {
            return memo[usebit];
        }

        for (int i = 1; i <= maxchoose; i++) {
            int mask = 1 << i;

            // FIX 1: Check if 'i' has already been used
            if (usebit & mask) continue;

            // FIX 2 & 3: Win immediately OR force opponent into a loss
            if (currtotal + i >= dest || !canwin(usebit | mask, currtotal + i, maxchoose, dest)) {
                return memo[usebit] = true;
            }
        }

        // Return false ONLY after testing all possible moves
        return memo[usebit] = false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;

        // FIX 4: Handle edge cases
        if (desiredTotal <= 0) return true;
        if (sum < desiredTotal) return false;

        return canwin(0, 0, maxChoosableInteger, desiredTotal);
    }
};