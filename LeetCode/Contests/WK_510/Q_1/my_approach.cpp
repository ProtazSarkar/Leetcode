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
    int secondsBetweenTimes(string startTime, string endTime) {
        int coff[3] = {3600,60,1};
        int st[3];
        int et[3];

        int n=startTime.length();
        int j=0;
        for(int i=0;i<n;i+=3){
            st[j] = stoi(startTime.substr(i,2));
            et[j] = stoi(endTime.substr(i,2));
            j++;
        }

        for(int i=2;i>=0;i--){
            if(et[i]<st[i]){
                if(i-1 >=0){
                    et[i-1]--;
                    et[i]+=60;
                }
            }
        }
        int ans=0;
        for(int i=0;i<3;i++){
            ans+=(coff[i]*(et[i]-st[i]));
        }
        return ans;
    }
};