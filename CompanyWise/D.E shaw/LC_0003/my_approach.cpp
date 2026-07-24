#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        vector<int> count(26,0);
        int ans=0;

        int j=0;
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            ans=max(ans,(i-j));
            while(count[s[i]-'a']>1){
                count[s[j]-'a']--;
                j++;
            }
        }
        return ans;
    }
};