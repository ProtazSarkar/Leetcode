#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<int>> matrix(n, vector<int>(n, -1));

        // build graph
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (matrix[u][v] == -1 || matrix[u][v] > w)
                matrix[u][v] = w;

            if (matrix[v][u] == -1 || matrix[v][u] > 2 * w)
                matrix[v][u] = 2 * w;
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (matrix[u][v] != -1) {
                    int cost = matrix[u][v];

                    if (dist[v] == -1 || dist[v] > dist[u] + cost) {
                        dist[v] = dist[u] + cost;
                        q.push(v);
                    }
                }
            }
        }

        // if no path exists
        return dist[n - 1];
    }
};

int main(){
  //testing code...
  return 0;
}