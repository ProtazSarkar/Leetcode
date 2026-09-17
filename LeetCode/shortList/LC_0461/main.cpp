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
    int hammingDistance(int x, int y) {
        int xorv = x ^ y;
        int dis = 0;

        while(xorv > 0){
            xorv = xorv & (xorv-1);
            dis ++;
        }
        return dis;
    }
};