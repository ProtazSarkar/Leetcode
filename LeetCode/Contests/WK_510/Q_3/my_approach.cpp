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

class Solution {
    int M,N,K;
    vector<string> grid;
    int countpaths(vector<string>& grid){
        int m= grid.size();
        int n = grid[0].size();

        if(grid[0][0] == '#' || grid[m-1][n-1] == '#'){
            return 0;
        }

        vector<vector<int>> arr(m,vector<int>(n,0));
        arr[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '#')   continue;
                if(i-1 >= 0)    arr[i][j]+=arr[i-1][j];
                if(j-1 >= 0)    arr[i][j]+=arr[i][j-1];
            }
        }

        return arr[m-1][n-1];
    }

     

public:
    vector<string> createGrid(int m, int n, int k) {
        
    }
};