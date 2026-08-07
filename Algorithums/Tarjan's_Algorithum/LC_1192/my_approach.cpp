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
    void dfs(int node,int parent,int &time,
        vector<vector<int>>& adj,
        vector<int>& discover_time,
        vector<int>& low,
        vector<vector<int>>& critical_edges
    ){
        discover_time[node] = low[node] = ++time;

        for(int neb : adj[node]){
            if(neb == parent)   continue;
            if(discover_time[neb] == -1){
                //neighbour is not visited 
                dfs(neb,node,time,adj,discover_time,low,critical_edges);

                //update the low
                low[node] = min(low[node],low[neb]);

                if(low[neb] > discover_time[node]){
                    //critical edge
                    critical_edges.push_back({node,neb});
                }
            }
            
            else{
                low[node] = min(low[node],discover_time[neb]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto con : connections){
            int u=con[0];
            int v=con[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> low(n,-1);
        vector<int> disc(n,-1);
        vector<vector<int>> ans;

        int time = 0;
        dfs(0,-1,time,adj,disc,low,ans);
        return ans;
    }
};