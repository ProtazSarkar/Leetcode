#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    const int INF = 1e9;
    const int MOD = 1e9 + 7;

    pair<int, int> dp[101][101];
    bool visited[101][101];

    pair<int, int> solve(vector<string>& boards, int i, int j) {
        int n = boards.size();

        // Base case 1: Reached the target 'E' (top-left)
        if (i == 0 && j == 0) {
            return {0, 1}; 
        }

        // Base case 2: Hit an obstacle 'X'
        if (boards[i][j] == 'X') {
            return {-INF, 0}; 
        }

        // Memoization check
        if (visited[i][j]) {
            return dp[i][j];
        }

        int w = 0;
        if (boards[i][j] <= '9' && boards[i][j] >= '0') {
            w = boards[i][j] - '0';
        }

        pair<int, int> diagonal = {-INF, 0}, up = {-INF, 0}, left = {-INF, 0};

        // Up-Left Diagonal Move
        if (i - 1 >= 0 && j - 1 >= 0) {
            diagonal = solve(boards, i - 1, j - 1);
        }
        // Up Move
        if (i - 1 >= 0) {
            up = solve(boards, i - 1, j);
        }
        // Left Move (Fixed the typo here!)
        if (j - 1 >= 0) {
            left = solve(boards, i, j - 1);
        }

        // Find the maximum weight among valid paths
        int max_weight = max({diagonal.first, up.first, left.first});
        
        // If all directions ahead are blocked, this cell is a dead end
        if (max_weight < 0) {
            visited[i][j] = true;
            return dp[i][j] = {-INF, 0};
        }

        // Accumulate paths safely
        int total_count = 0;
        if (max_weight == diagonal.first) total_count = (total_count + diagonal.second) % MOD;
        if (max_weight == up.first)       total_count = (total_count + up.second) % MOD;
        if (max_weight == left.first)     total_count = (total_count + left.second) % MOD;

        visited[i][j] = true;
        return dp[i][j] = {max_weight + w, total_count};
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        
        // Reset memo structures
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        auto [a, b] = solve(board, n - 1, n - 1);
        
        if (a < 0) return {0, 0};
        return {a, b};
    }
};