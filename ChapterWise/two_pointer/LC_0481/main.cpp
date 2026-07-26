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
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1; // "122" has one '1' in the first 1-3 elements

        string s = "122";
        int next_num = 1; // We alternate between writing '1' and '2'
        int i = 2;        // Pointer to check what length to add next

        while (s.length() < n) {
            // How many times should we repeat next_num? 
            // Look at the digit at index `i` in our string.
            int repeat = s[i] - '0'; 

            // Append `repeat` number of `next_num` characters
            string append_str(repeat, next_num + '0');
            s += append_str;

            // Flip next_num between 1 and 2 (1 -> 2, 2 -> 1)
            next_num = 3 - next_num;
            i++;
        }

        // Count the number of '1's in the first n characters
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                count++;
            }
        }

        return count;
    }
};