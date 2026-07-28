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

class LRUCache {
    int cap;
    // Store pairs of {key, value} in the list
    list<pair<int, int>> l;
    // Map points directly to the iterator in the list for O(1) access/removal
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        // Move the accessed node to the front (most recently used)
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        // If key already exists, update its value and move it to the front
        if (m.find(key) != m.end()) {
            m[key]->second = value;
            l.splice(l.begin(), l, m[key]);
            return;
        }
        
        // If capacity is reached, remove the least recently used item (the back of the list)
        if (l.size() == cap) {
            int lru_key = l.back().first;
            l.pop_back();
            m.erase(lru_key);
        }
        
        // Insert the new item at the front of the list
        l.push_front({key, value});
        m[key] = l.begin();
    }
};