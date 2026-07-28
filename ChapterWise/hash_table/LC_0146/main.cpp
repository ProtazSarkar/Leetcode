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
    unordered_map<int, int> cache;
    unordered_map<int, int> time_map;
    // Min-heap stores pairs of {timestamp, key}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int time;
    int capacity;

public:
    LRUCache(int capacity) {
        this->time = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        // If the key doesn't exist, return -1 immediately without changing state
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        // Update recency since the key was accessed
        pq.push({time, key});
        time_map[key] = time;
        time++;

        return cache[key];
    }
    
    void put(int key, int value) {
        // If key already exists, update its value and treat it as a fresh access
        if (cache.find(key) != cache.end()) {
            cache[key] = value;
            pq.push({time, key});
            time_map[key] = time;
            time++;
            return;
        }

        // If the cache is full, we need to evict the least recently used item
        if (cache.size() >= capacity) {
            int k;
            while (true) {
                auto [t, ke] = pq.top();
                pq.pop();
                
                // Lazy deletion check: Ensure the timestamp matches the latest timestamp for this key
                if (t == time_map[ke]) {
                    k = ke;
                    break;
                }
            }

            // Remove the stale key from tracking structures
            cache.erase(k);
            time_map.erase(k);
        }

        // Insert the new key-value pair
        cache[key] = value;
        pq.push({time, key});
        time_map[key] = time;
        time++;
    }
};