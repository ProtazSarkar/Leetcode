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
    struct node{
        bool is_endofword;
        node* children[26];

        node(){
            is_endofword = false;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
        }
    };

    node* root;

    void insert(string word){
        node* curr = root;
        for(char c : word){
            int idx = c-'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = new node();
            }
            curr = curr->children[idx];
        }
        curr-> is_endofword = true;
    }

    vector<int> memo;
    bool solve(int i,string s){
        if(i == s.length()){
            return true;
        }

        if(memo[i] != -1)   return memo[i];

        node* curr = root;
        for(int j=i;j<s.length();j++){
            int idx = s[j] - 'a';
            if(curr->children[idx] == NULL) break;

            curr = curr->children[idx];
            if(curr->is_endofword){
                if(solve(j+1,s)){
                    return memo[i] = 1;
                }
            }
        }
        return memo[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new node();

        for(string word : wordDict){
            insert(word);
        }

        int  n = s.length();
        memo.assign(n,-1);
        return solve(0,s);
    }
};