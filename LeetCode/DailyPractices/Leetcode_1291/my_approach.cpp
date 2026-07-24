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
    int digit_count(int n){
        int count =0;
        while(n){
            count ++;
            n/=10;
        }
        return count;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> digits={1,2,3,4,5,6,7,8,9};

        vector<int> ans;

        for(int win = digit_count(low);win <= 10 ; win++){
            int j=0;int num=0;
            for(int i=0;i<10;i++){
                num=(num*10) + digits[i];
                if(i-j+1 < win) continue;
                if(i-j+1 == win){
                    if(num >= low && num <= high){
                        ans.push_back(num);
                    }
                    num=(num % pow(10,win));
                    j++;
                }
            }

            if(num > high) break;
        }

        return ans;
    }
};