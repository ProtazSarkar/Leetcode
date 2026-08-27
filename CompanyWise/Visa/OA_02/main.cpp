#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTotalWalk(int n, vector<int>& gasStations) {
        int totalWalk = 0;
        int reach = 0; // Maximum position reachable via flying/starting
        
        for (int g : gasStations) {
            // If the gas station is beyond current reachable distance, walk to it
            if (g > reach) {
                totalWalk += (g - reach);
                reach = g; // Update position to the gas station
            }
            // Refuel at gas station (can fly 10 units forward)
            reach = max(reach, g + 10);
        }

        // Final leg: from last reachable point to destination n
        if (n > reach) {
            totalWalk += (n - reach);
        }

        return totalWalk;
    }
};