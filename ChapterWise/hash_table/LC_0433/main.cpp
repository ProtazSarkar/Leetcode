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

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
    bool is_valid(const string& s1, const string& s2) {
        int mismatch = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) mismatch++;
        }
        return mismatch == 1;
    }

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, vector<string>> adj;
        int bank_size = bank.size();

        // 1. Connect startGene to all valid bank genes
        for (int i = 0; i < bank_size; i++) {
            if (is_valid(startGene, bank[i])) {
                adj[startGene].push_back(bank[i]);
            }
        }

        // 2. Build undirected graph among bank genes
        for (int i = 0; i < bank_size; i++) {
            string key = bank[i];
            for (int j = i + 1; j < bank_size; j++) {
                if (is_valid(key, bank[j])) {
                    adj[key].push_back(bank[j]);
                    adj[bank[j]].push_back(key); // Fixed: Undirected edge
                }
            }
        }

        // 3. BFS Setup
        queue<string> q;
        unordered_set<string> visited;

        q.push(startGene);
        visited.insert(startGene);

        int level = 0;

        while (!q.empty()) {
            int sz = q.size(); // Fixed: Freeze queue size for level-by-level traversal

            for (int i = 0; i < sz; i++) {
                string u = q.front();
                q.pop();

                if (u == endGene) return level;

                for (const string& v : adj[u]) {
                    if (visited.find(v) == visited.end()) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
            level++;
        }

        return -1;
    }
};