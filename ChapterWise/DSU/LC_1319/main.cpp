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
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(parent[i] == i)  return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i,int j){
        int root_i = find(i);
        int root_j = find(j);

        if(root_i != root_j){
            if(rank[root_i] > rank[root_j]){
                parent[root_j] = root_i; 
            }
            else if(rank[root_i] < rank[root_j]){
                parent[root_i] = root_j;
            }
            else if(rank[root_i] == rank[root_j]){
                parent[root_j] = root_i;
                rank[root_i]++;
            }

            return true;
        }
        return false;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        int extra = 0;
        int component = n;

        for(const vector<int> con : connections){
            int i = con[0];
            int j = con[1];

            if(unite(i,j)){
                component --;
            }else{
                extra ++;
            }
        }

        int req = component -1;
        return (extra >= req) ? req : -1;
    }
};