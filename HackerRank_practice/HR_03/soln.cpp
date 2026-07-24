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

int formingMagicSquare(vector<vector<int>> s) {
    // All 8 possible 3x3 magic squares
    vector<vector<vector<int>>> possible_squares = {
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}
    };

    int min_cost = INT_MAX;

    // Compare input matrix 's' with each of the 8 valid magic squares
    for (int p = 0; p < 8; p++) {
        int current_cost = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                current_cost += abs(s[i][j] - possible_squares[p][i][j]);
            }
        }
        min_cost = min(min_cost, current_cost);
    }

    return min_cost;
}