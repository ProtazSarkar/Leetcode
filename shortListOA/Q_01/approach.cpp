#include <iostream>
#include <sstream>

// Containers
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>

// Associative Containers (Trees/Hashes)
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

// Algorithms & Utilities
#include <algorithm>
#include <numeric>
#include <climits>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
    int MOD = 1e9 + 7;
    int memo[55][5005]; // dp table: memo[i][pre + 1]

    int digit_sum(int n) {
        int sum = 0;
        while(n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int solve(int i, int pre, const vector<int>& req_sums, const vector<vector<int>>& map) {
        if(i >= req_sums.size()) {
            return 1;
        }
        
        // Memoization check (-1 is shifted to index 0, so pre + 1 ranges from 0 to 5001)
        if(memo[i][pre + 1] != -1) {
            return memo[i][pre + 1];
        }

        int req_sum = req_sums[i];
        long long take = 0;
        
        for(int num : map[req_sum]) {
            if(pre == -1 || num >= pre) {
                take = (take + solve(i + 1, num, req_sums, map)) % MOD;
            }
        }

        return memo[i][pre + 1] = take;
    }

public:
    int countValidArrays(const vector<int>& required_sums) {
        int n = required_sums.size();
        
        vector<vector<int>> map(40);
        for(int i = 0; i <= 5000; i++) {
            int ds = digit_sum(i);
            map[ds].push_back(i);
        }
        
        // Initialize memoization table with -1
        memset(memo, -1, sizeof(memo));
        
        return solve(0, -1, required_sums, map);
    }
};

int main() {
    Solution sol;
    vector<int> required_sums = {30, 31, 31};
    cout << "Total ways: " << sol.countValidArrays(required_sums) << endl;
    return 0;
}