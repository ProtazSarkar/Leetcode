class Solution {
    // Fixed: Added target 't' to the recursive calls
    bool solve(vector<int>& arr, int l, int h, int t){
        if(l > h) return false;
        int mid = l + (h - l) / 2;
        if(arr[mid] == t) return true;
        if(arr[mid] > t) return solve(arr, l, mid - 1, t);
        return solve(arr, mid + 1, h, t);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        int row = matrix.size();
        int col = matrix[0].size(); // Fixed: getting actual column count
        
        for(int i = 0; i < row; i++){
            // Optimization: Only search rows where the target could actually fit
            if(matrix[i][col - 1] >= target){
                if(solve(matrix[i], 0, col - 1, target)) return true;
                
                /* Note: If this is 'Search a 2D Matrix I' (fully sorted), 
                   you can return false here. If it's 'Search a 2D Matrix II' 
                   (rows/cols sorted independently), you must keep checking 
                   subsequent rows! 
                */
            }
        }
        return false;
    }
};
