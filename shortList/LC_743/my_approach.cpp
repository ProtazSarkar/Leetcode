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
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto e : times){
            int u=e[0];
            int v=e[1];
            int w=e[2];

            adj[u].push_back({v,w});
        }

        vector<int> best(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        best[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [b,u] = pq.top();
            pq.pop();

            if(b>best[u])   continue;

            for(auto [v,w] : adj[u]){
                int nb=b+w;
                if(best[v] > nb){
                    best[v]=nb;
                    pq.push({nb,v});
                }
            }
        }

        return (best[n] == INT_MAX) ? -1 : best[n];
    }
};