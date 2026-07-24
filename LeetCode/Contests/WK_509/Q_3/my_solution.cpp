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
    const int MAX = 1e6 + 1;
    const int MOD = 1e9 + 7;
    vector<int> is_prime(MAX,1);
    vector<int> primes;
    
    void discard(int k){
        for(int i=2;i*k < MAX ; i++){
            is_prime[i*k] = 0;
        }
    }
    void constructPrims(){
        is_prime[0]=is_prime[1]=0;
        for(int num=0;num<MAX;num++){
            if(is_prime[num]==0){
                continue;
            }
            primes.push_back(num);
            discard(num);
        }
    }
public:
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        constructPrims();

        unordered_map<long long,int> map;

        for(int i = primes.size()-1;i>=0;i--){
            int p = primes[i];
            int curr_sum;
            if(! nums[0] % p){
                curr_sum = nums[0];
            }else{
                curr_sum=-nums[0];
            }

            long long max_sum = curr_sum;
            for(int i=1;i<n;i++){
                if(nums[i]%p == 0){
                    curr_sum = max(curr_sum,curr_sum+nums[i]);
                }else{
                    curr_sum = max(curr_sum,curr_sum-nums[i]);
                }
                max_sum = max(max_sum,curr_sum);
            }
            map[max_sum] = p;
        }

        long long _max=INT_MIN;
        for(auto [k,v] : map){
            _max=max(k,_max);
        }

        return (_max * map[_max])%MOD;
    }
};