class Solution {
  const int INTMAX = 1e9;

  bool is_possible(const vector<vector<int>> &arr, int x) {
    int n = arr.size();

    if (arr[0][0] < x)
      return false;

    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      if (r == n - 1 && c == n - 1)
        return true;

      for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] &&
            arr[nr][nc] >= x) {

          visited[nr][nc] = 1;
          q.push({nr, nc});
        }
      }
    }

    return false;
  }

  int bs(vector<vector<int>> &dest, int l, int h) {
    if (l > h)
      return h;

    int mid = l + (h - l) / 2;

    if (is_possible(dest, mid))
      return bs(dest, mid + 1, h);
    else
      return bs(dest, l, mid - 1);
  }

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

    int maxDest = 0;

    while (!q.empty()) {

      auto [r, c] = q.front();
      q.pop();

      for (int k = 0; k < 4; k++) {

        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n && dest[nr][nc] == INTMAX) {

          dest[nr][nc] = dest[r][c] + 1;
          maxDest = max(maxDest, dest[nr][nc]);
          q.push({nr, nc});
        }
      }
    }

    return bs(dest, 0, maxDest);
  }
};