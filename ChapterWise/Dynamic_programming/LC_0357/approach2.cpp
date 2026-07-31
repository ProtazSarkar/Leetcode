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

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10; // n=1 includes 0 through 9 (10 numbers)

        // choice_count[i] will store the number of choices for the i-th digit position
        vector<int> choice_count(n + 1);
        choice_count[1] = 9; // First digit can be 1-9 (9 choices)
        
        int available = 9;
        for (int i = 2; i <= n; i++) {
            choice_count[i] = available; // Second digit onwards can include 0
            available--;
        }

        int total_ans = 1; // Start with 1 for n = 0 (the number 0)
        
        // We need to sum up numbers of length 1, 2, ..., up to n
        for (int length = 1; length <= n; length++) {
            int current_length_ways = 9; // First position
            for (int i = 2; i <= length; i++) {
                current_length_ways *= choice_count[i];
            }
            total_ans += current_length_ways;
        }

        return total_ans;
    }
};