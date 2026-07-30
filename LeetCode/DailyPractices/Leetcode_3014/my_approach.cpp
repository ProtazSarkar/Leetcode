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
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        for(char c : word){
            count[c-'a']++;
        }

        vector<int> char_to_key(26, -1); // char to corresponding key
        vector<vector<char>> key_to_char(10); // key to char map

        vector<pair<int, char>> freq; // freq to char map
        freq.reserve(26);

        for(int i = 0; i < 26; i++){
            int cnt = count[i];
            char c = 'a' + i;
            if(cnt != 0){
                freq.push_back({cnt, c});
            }
        }

        // Sort in descending order of frequency to assign most frequent chars first
        sort(freq.begin(), freq.end(), greater<pair<int, char>>());

        // Build the map
        int limit = 8;
        int k = 0;

        for(auto pair : freq){
            int cnt = pair.first;
            char c = pair.second;

            int char_idx = c - 'a';
            int key = (k++) % limit;

            char_to_key[char_idx] = key;
            key_to_char[key].push_back(c);
        }

        // Ans calculate
        int ans = 0;
        for(char c : word){
            int key = char_to_key[c - 'a']; // Fixed parentheses to brackets
            for(int k = 0; k < key_to_char[key].size(); k++){
                if(key_to_char[key][k] == c){
                    ans += k + 1;
                    break;
                }
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}