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
    void reverse(vector<int>& arr,int i,int j){
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size()*grid[0].size();
        vector<int> arr;
        arr.reserve(n);

        //flatten the grid
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr.push_back(grid[i][j]);
            }
        }

        //normalize the k
        k=k%n;

        reverse(arr,0,n-1);
        reverse(arr,0,k-1);
        reverse(arr,k,n-1);

        int m=grid.size();
        n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        int g=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=arr[g++];
            }
        }

        return ans;
    }
};