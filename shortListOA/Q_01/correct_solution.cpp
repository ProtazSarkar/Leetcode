#include <iostream>
#include <vector>

using namespace std;

class Solution {
    static constexpr int MAX_VALUE = 5000;
    static constexpr int MOD = 1'000'000'007;

    static int digitSum(int value) {
        int sum = 0;
        while (value > 0) {
            sum += value % 10;
            value /= 10;
        }
        return sum;
    }

public:
    int countValidArrays(const vector<int>& required_sums) {
        vector<int> digit_sums(MAX_VALUE + 1);
        for (int value = 0; value <= MAX_VALUE; ++value) {
            digit_sums[value] = digitSum(value);
        }

        // next[previous] is the number of valid suffixes after the current position.
        vector<int> next(MAX_VALUE + 1, 1);

        for (int index = static_cast<int>(required_sums.size()) - 1;
             index >= 0;
             --index) {
            vector<int> current(MAX_VALUE + 1, 0);
            long long suffix_count = 0;

            // Scanning backwards makes suffix_count represent all choices >= previous.
            for (int previous = MAX_VALUE; previous >= 0; --previous) {
                if (digit_sums[previous] == required_sums[index]) {
                    suffix_count = (suffix_count + next[previous]) % MOD;
                }
                current[previous] = static_cast<int>(suffix_count);
            }

            next = move(current);
        }

        return next[0];
    }
};

int main() {
    Solution solution;
    vector<int> required_sums = {30, 31, 31};
    cout << "Total ways: "
         << solution.countValidArrays(required_sums)
         << '\n';
    return 0;
}
