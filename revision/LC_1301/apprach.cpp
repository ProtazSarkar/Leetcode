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

vector<int> pathsWithMaxScore(vector<string> &board)
{
    int n = board.size();
    int MOD = 1e9 + 7;

    vector<vector<int>> dp_score(n, vector<int>(n, -1));
    vector<vector<int>> dp_path(n, vector<int>(n, 0));

    dp_score[n - 1][n - 1] = 0;
    dp_path[n - 1][n - 1] = 1;

    vector<int> dr = {1, 0, 1};
    vector<int> dc = {0, 1, 1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == n - 1 && j == n - 1 || board[i][j] == 'X')
            {
                continue;
            }
            int max_s = -1;
            int path_sum = 0;

            for (int k = 0; k < 3; k++)
            {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if (ni < n && nj < n && dp_score[ni][nj] != -1)
                {
                    if (max_s < dp_score[ni][nj])
                    {
                        max_s = dp_score[ni][nj];
                        path_sum = dp_path[ni][nj];
                    }
                    else if (dp_score[ni][nj] == max_s)
                    {
                        path_sum += dp_path[ni][nj];
                    }
                }
            }
            if (max_s != -1)
            {
                int w = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                dp_score[i][j] = (max_s + w) % MOD;
                dp_path[i][j] = path_sum;
            }
        }
    }

    return (dp_score[0][0] < 0) ? {0,0} : {dp_score[0][0],dp_path[0][0]};
}