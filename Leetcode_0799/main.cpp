class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // 101 x 101 is safe (approx 80KB of memory)
        double mat[101][101] = {0.0}; 
        mat[0][0] = (double)poured;
        
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (mat[i][j] > 1.0) {
                    double overflow = (mat[i][j] - 1.0) / 2.0;
                    mat[i + 1][j] += overflow;
                    mat[i + 1][j + 1] += overflow;
                }
            }
        }
        
        return min(1.0, mat[query_row][query_glass]);
    }
};
