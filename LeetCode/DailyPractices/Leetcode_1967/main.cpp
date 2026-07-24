#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> map;

        int n=word.length();

        for(int i=0;i<n;i++){
            string key="";
            for(int j=i;j<n;j++){
                key.push_back(word[j]);
                map[key]++;
            }
        }

        int count=0;

        for(string q : patterns){
            if(map.find(q)!=map.end()){
                count++;
            }
        }

        return count;
    }
};