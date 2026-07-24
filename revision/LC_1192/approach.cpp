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

void dfs(
    int node , 
    int parent ,
    int &time,
    vector<vector<int>> &adj,
    vector<int> discover,
    vector<int> low,
    vector<vector<int>>& criticalEdges
){
    discover[node] = low[node] = ++time;
    for(int neb : adj[node]){
        if(neb == parent)   continue;
        //if the neighbor is not visited
        if(discover[neb] == -1){
            dfs(neb,node,time,adj,discover,low,criticalEdges);

            //upon return update the low values of the current node
            low[node] = min(low[node],low[neb]);
            if(low[neb] > discover[node]){
                //means critical edge
                criticalEdges.push_back({node,neb});
            }
        }else{
            low[node] = min(low[node],discover[neb]);
        }
    }
}

vector<vector<int>> criticalConnections(int n,vector<vector<int>> adj){
    vector<int> discover(n,-1);
    vector<int> low(n,-1);
    vector<vector<int>> criticalConnections;

    int time = 0;

    dfs(0,-1,time,adj,discover,low,criticalConnections);
    return criticalConnections;
}