class Solution {
  const int INTMAX = 1e9;

public:
  int maximumSafenessFactor(vector<vector<int>> &grid) {

    int n = grid.size();

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return 0;

    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    vector<vector<int>> dest(n, vector<int>(n, INTMAX));

    queue<pair<int, int>> q;

    // Multi-source BFS
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          dest[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {

      auto [r, c] = q.front();
      q.pop();

      for (int k = 0; k < 4; k++) {

        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

          if (dest[nr][nc] == INTMAX) {

            dest[nr][nc] = dest[r][c] + 1;
            q.push({nr, nc});
          }
        }
      }
    }

    // Modified Dijkstra
    vector<vector<int>> best(n, vector<int>(n, -1));

    priority_queue<tuple<int, int, int>> pq;

    best[0][0] = dest[0][0];
    pq.push({dest[0][0], 0, 0});

    while (!pq.empty()) {

      auto [b, r, c] = pq.top();
      pq.pop();

      if (b < best[r][c])
        continue;

      if (r == n - 1 && c == n - 1)
        return b;

      for (int k = 0; k < 4; k++) {

        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

          int nb = min(b, dest[nr][nc]);

          if (nb > best[nr][nc]) {

            best[nr][nc] = nb;
            pq.push({nb, nr, nc});
          }
        }
      }
    }

    return best[n - 1][n - 1];
  }
};