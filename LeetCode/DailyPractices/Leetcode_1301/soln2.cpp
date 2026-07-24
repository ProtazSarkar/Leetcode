#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;

        vector<vector<int>> dp_score(n, vector<int>(n, -1));
        vector<vector<int>> dp_path(n, vector<int>(n, 0));

        dp_score[n-1][n-1] = 0;
        dp_path[n-1][n-1] = 1;

        vector<int> dr = {1, 0, 1};
        vector<int> dc = {0, 1, 1};

        // BUG FIX 1: Run the loops backwards from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                if ((i == n - 1 && j == n - 1) || board[i][j] == 'X') {
                    continue;
                }
                
                int max_s = -1;
                int path_sum = 0;

                for (int k = 0; k < 3; k++) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if (ni < n && nj < n && dp_score[ni][nj] != -1) {
                        if (max_s < dp_score[ni][nj]) {
                            max_s = dp_score[ni][nj];
                            path_sum = dp_path[ni][nj];
                        } else if (dp_score[ni][nj] == max_s) {
                            path_sum = (path_sum + dp_path[ni][nj]) % MOD;
                        }
                    }
                }

                if (max_s != -1) {
                    int w = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                    // BUG FIX 2: Removed % MOD from the score calculation
                    dp_score[i][j] = max_s + w; 
                    dp_path[i][j] = path_sum;
                }
            }
        }

        if (dp_score[0][0] < 0) {
            return {0, 0};
        }
        return {dp_score[0][0], dp_path[0][0]};
    }
};