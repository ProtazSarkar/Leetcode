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
    bool is_complete_component(int i,vector<vector<int>>& adj,vector<bool>& visited){
        queue<int> q;
        vector<int> component;
        component.push_back(i);
        q.push(i);
        visited[i]=true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v: adj[u]){
                if(!visited[v]){
                    q.push(v);
                    component.push_back(v);
                    visited[v]=true;
                }
            }
        }

        int k=component.size();
        for(int c : component){
            if(adj[c].size() != (k-1)){
                return false;
            }
        }
        return true;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e : edges){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i] && is_complete_component(i,adj,visited)){
                ans++;
            }
        }

        return ans;
    }
};