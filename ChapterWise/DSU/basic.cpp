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

class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        rank.assign(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int i){
        if(parent[i] == i)  return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i,int j){
        int parent_i = find(i);
        int parent_j = find(j);

        if(parent_i != parent_j){
            if(rank[parent_i] < rank[parent_j]){
                parent[parent_i] = parent_j;
            }
            else if(rank[parent_i] > rank[parent_j]){
                parent[parent_j] = parent_i;
            }
            else if(rank[parent_i] == rank[parent_j]){
                parent[parent_j] = parent_i;
                rank[parent_i]++;
            }
            return true;
        }
        return false;
    }
};