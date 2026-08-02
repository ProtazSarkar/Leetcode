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
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count_a = 0,count_b = 0,count_c = 0;

        int ans = 0;

        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')   count_a++;
            if(s[i]=='b')   count_b++;
            if(s[i]=='c')   count_c++;

            while(count_a >0 && count_b>0 && count_c>0){
                ans += (n-i);
                if(s[j] == 'a') count_a--;
                if(s[j] == 'b') count_b--;
                if(s[j] == 'c') count_c--;
                j++;
            }
        }
        return ans;
    }
};