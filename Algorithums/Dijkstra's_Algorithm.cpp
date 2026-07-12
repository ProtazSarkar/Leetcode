#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int v,vector<vector<pair<int,int>>>& adj,int src){
        const int INF=1e9;

        vector<int> dest(v,INF);

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >pq;

        dest[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();

            if(auto)
        }
    }
};