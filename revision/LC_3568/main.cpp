#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
    struct state {
        int r, c, e, litters;
    };

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> litters_id(m, vector<int>(n, -1));
        int litter_count = 0;
        int sr = 0, sc = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'L') {
                    litters_id[i][j] = litter_count++;
                }
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
            }
        }

        int target = (1 << litter_count) - 1;
        if (target == 0) return 0;

        int start_litter = 0;
        if (litters_id[sr][sc] != -1) {
            start_litter |= (1 << litters_id[sr][sc]);
        }
        if (start_litter == target) return 0;

        // Size energy + 1 to handle energy values from 0 to energy
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << litter_count, false)
                )
            )
        );

        queue<state> q;
        q.push({sr, sc, energy, start_litter});
        visited[sr][sc][energy][start_litter] = true;

        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};

        int move = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, e, litters] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;

                    // Compute next energy
                    int ne = (classroom[nr][nc] == 'R') ? energy : e - 1;
                    if (ne < 0) continue; // Cannot move with no energy left

                    // Compute next litter mask
                    int nl = litters;
                    if (litters_id[nr][nc] != -1) {
                        nl |= (1 << litters_id[nr][nc]);
                    }

                    if (nl == target) return move + 1;

                    if (!visited[nr][nc][ne][nl]) {
                        visited[nr][nc][ne][nl] = true; // Mark when pushing
                        q.push({nr, nc, ne, nl});
                    }
                }
            }
            move++;
        }

        return -1;
    }
};