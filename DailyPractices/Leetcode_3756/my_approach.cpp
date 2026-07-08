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
    const int MOD = 1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length();

        vector<int> prefix_digit_sum(n);
        vector<long long> prefix_num(n);

        prefix_digit_sum[0]=(s[0]-'0');
        prefix_num[0]=(s[0]-'0');

        for(int i=1;i<n;i++){
            int d=s[i] - '0';
            prefix_digit_sum[i]=(d+prefix_digit_sum[i-1]);
            if(d == 0){
                prefix_num[i]=prefix_num[i-1];
            }else{
                prefix_num[i]=(d+(10*(long long)prefix_num[i-1])%MOD)%MOD;
            }
        }

        vector<int> ans;
        for(auto q : queries){
            int l=q[0];
            int r=q[1];

            int x;int sum;

            if(l==0){
                x=prefix_num[r];
                sum=prefix_digit_sum[r];
                ans.push_back((x*sum)%MOD);
            }else{
                int p=r-l;
                x=prefix_num[r]-(pow(10,p)*prefix_num[l-1]);
                sum=prefix_digit_sum[r]-prefix_digit_sum[l-1];
                ans.push_back((x*sum)%MOD);
            }
        }

        return ans;
    }
};