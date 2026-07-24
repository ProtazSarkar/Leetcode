#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int INF=1e9;
        vector<int> lowers(26,-1);
        vector<int> uppers(26,INF);

        for(int i=0;i<word.length();i++){
            char c=word[i];
            if(word[i]>='a' && word[i]<='z'){
                lowers[c-'a']=max(lowers[c-'a'],i);
            }
            if(c>='A' && c<='Z'){
                uppers[c-'A']=min(uppers[c-'A'],i);
            }
        }

        int ans=0;

        for (int i=0;i<26;i++){
            if(lowers[i]!=-1 && uppers[i]!=INF && lowers[i]<uppers[i]){
                ans++;
            }
        }

        return ans;
    }
};