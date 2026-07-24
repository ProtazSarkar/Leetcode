#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
    const long long INF=1e18;
    bool is_possible(int t,vector<vector<pair<int,int>>>& adj,vector<bool>& online,long long k){
        int n=online.size();

        queue<pair<long long , int>> q;
        q.push({0,0});

        while(!q.empty()){
            auto [total_w,u] = q.front();
            q.pop();

            if(u==n-1){
                return true;
            }

            for(auto [v,w] : adj[u]){
                long long new_w=total_w+w;
                if(new_w<k && online[v] && w<=t){
                    q.push({new_w,v});
                }
            }
        }

        return false;

    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> weights;
    
        for(auto e : edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];

            adj[u].push_back({v,w});
            weights.push_back(w);
            
        }

        sort(weights.begin(),weights.end());
        int left=0;
        int right=weights.size()-1;
        int ans=-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(is_possible(weights[mid],adj,online,k)){
                ans=weights[mid];
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};