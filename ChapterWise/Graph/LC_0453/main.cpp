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
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        visited[r][c] = true;

        int result = 4;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                result--; // Subtract an edge for every neighboring land cell
                if (!visited[nr][nc]) {
                    result += dfs(nr, nc, grid, visited);
                }
            }
        }

        return result;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { // Fixed j++ typo
                if (grid[i][j] == 1 && !visited[i][j]) { // Fixed visited spelling typo
                    return dfs(i, j, grid, visited); // Return immediately since there's only 1 island
                }
            }
        }
        return 0;
    }
};