#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    const int INF=1e9;

    int div(int x,int y){
        if(y%x){
            return (y/x)+1;
        }else{
            return y/x;
        }
    }

    bool is_possible(vector<int>& piles,int k,int h){
        long long total_hr=0;
        for(int pile : piles){
            total_hr+=div(pile,k);
        }
        return total_hr<=h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int left=INF;int right=-INF;
        for(int i=0;i<n;i++){
            left=min(left,piles[i]);
            right=max(right,piles[i]);
        }
        left--;
        right++;
        int ans=0;

        
        while(left<=right){
            int mid=left+(right-left)/2;
            if(is_possible(piles,mid,h)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }

        return ans;
    }
};