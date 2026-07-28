#include <unordered_map>
#include <list>

class LRUCache {
private:
    int cap;
    // List stores pairs of {key, value}
    std::list<std::pair<int, int>> cacheList;
    // Map stores key mapped to an iterator of the list
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // If key is not found, return -1
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        
        // If key exists, promote it to the most recently used position (front of the list)
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        
        return cacheMap[key]->second;
    }
    
    void put(int key, int value) {
        // If key already exists, update its value and move it to the front
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }
        
        // If capacity is reached, remove the least recently used item (back of the list)
        if (cacheList.size() >= cap) {
            int lruKey = cacheList.back().first;
            cacheList.pop_back();
            cacheMap.erase(lruKey);
        }
        
        // Insert the new key-value pair at the front of the list
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }
};