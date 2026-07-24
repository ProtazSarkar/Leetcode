#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
    const int INTMAX = 1e9;

public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        vector<vector<int>> dest(m, vector<int>(n, -INT_MAX));
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        >pq;

        dest[0][0] = health;
        pq.push({health, 0, 0});

        while (!pq.empty())
        {
            auto [h, r, c] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    if (grid[nr][nc] == 1)
                    {
                        h--;
                        int nh = max(h, dest[nr][nc]);
                        if (nh > dest[nr][nc])
                        {
                            dest[nr][nc] = nh;
                            pq.push({nh, nr, nc});
                        }
                        // restore health
                        h++;
                    }
                    else
                    {
                        int nh = max(h, dest[nr][nc]);
                        if (nh > dest[nr][nc])
                        {
                            dest[nr][nc] = nh;
                            pq.push({nh, nr, nc});
                        }
                    }
                }
            }
        }

        return dest[m-1][n-1]>0;
    }
};