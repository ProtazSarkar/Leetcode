#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
    struct State {
        int r, c, e, litters;
    };
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].length();

        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};

        int sr = -1, sc = -1;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        int litter_count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(classroom[i][j] == 'S'){
                    sr = i;
                    sc = j;
                } else if(classroom[i][j] == 'L'){
                    litter_id[i][j] = litter_count++;
                }
            }
        }

        if(litter_count == 0) return 0;
        int target = (1 << litter_count) - 1;

        // visited[r][c][energy][bitmask]
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << litter_count, false)
                )
            )
        );

        queue<State> q;
        q.push({sr, sc, energy, 0});
        visited[sr][sc][energy][0] = true;

        int moves = 0;

        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                State s = q.front();
                q.pop();

                if(s.litters == target) return moves;

                for(int k = 0; k < 4; k++){
                    int nr = s.r + dr[k];
                    int nc = s.c + dc[k];

                    if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if(classroom[nr][nc] == 'X') continue;
                    if(s.e == 0) continue; // Cannot move if energy is depleted

                    int ne = (classroom[nr][nc] == 'R') ? energy : s.e - 1;
                    int nl = s.litters;

                    if(classroom[nr][nc] == 'L'){
                        int pos = litter_id[nr][nc];
                        if(pos != -1) {
                            nl |= (1 << pos);
                        }
                    }

                    if(!visited[nr][nc][ne][nl]){
                        visited[nr][nc][ne][nl] = true;
                        q.push({nr, nc, ne, nl});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};