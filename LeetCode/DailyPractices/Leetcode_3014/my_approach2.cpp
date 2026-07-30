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

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> count(26, 0);

        for (char c : word)
        {
            count[c - 'a']++;
        }

        vector<pair<int, char>> freq;
        freq.reserve(26);

        for (int i = 0; i < 26; i++)
        {
            int cnt = count[i];
            char c = 'a' + i;

            freq.push_back({cnt, c});
        }

        sort(freq.begin(), freq.end(), greater<pair<int, char>>());
        // create a map of how many press to reach the char
        vector<int> press_count(26, -1);

        int i = 0;
        int n = freq.size();
        int curr_press = 1;
        while (i < n)
        {
            for (int k = 0; k < 8; k++)
            {
                if (i < n)
                {
                    auto pair = freq[i];
                    int char_idx = pair.second - 'a';
                    press_count[char_idx] = curr_press;
                }
                i++;
            }
            curr_press++;
        }

        int ans = 0;
        for(char c : word){
            ans += press_count[c-'a'];
        }

        return ans;
    }
};