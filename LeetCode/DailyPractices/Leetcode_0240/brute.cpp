class Solution {
    bool solve(vector<vector<int>>& mat, int iL, int jL, int iH, int jH, int t) {
        // Base case: boundaries crossed
        if (iL > iH || jL > jH) return false;

        int iMid = iL + (iH - iL) / 2;
        int jMid = jL + (jH - jL) / 2;

        if (mat[iMid][jMid] == t) return true;

        if (mat[iMid][jMid] > t) {
            // Target could be in: top-left, top-right, or bottom-left
            return solve(mat, iL, jL, iH, jMid - 1, t) || 
                   solve(mat, iL, jMid, iMid - 1, jH, t);
        } else {
            // Target could be in: bottom-right, top-right, or bottom-left
            return solve(mat, iL, jMid + 1, iH, jH, t) || 
                   solve(mat, iMid + 1, jL, iH, jMid, t);
        }
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        return solve(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }
};
