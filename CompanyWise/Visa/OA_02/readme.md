# README - Drone's Walk

## Problem Statement
A drone travels on a 1D number line from position `0` to `n`. You are given an integer array 
`gasStations` containing the positions of gas stations in sorted order.

- The drone starts at position 0 with **0 units of fuel**.
- When at a gas station, the drone refuels to maximum capacity, which allows it to fly up to **10 units** of distance.
- If the drone is at position `curr` with no remaining fuel and needs to reach the next position `target`, 
  it must **walk** the distance `(target - curr)`. Walking does not consume fuel.
- Calculate and return the **total distance** you must walk the drone to reach destination `n`.

## Example
Input: n = 42, gasStations = [1, 6, 11, 20, 30]
Output: 12
Explanation:
- Start at 0 with 0 fuel. Walk 1 unit to gasStation[0] (pos 1). Total walk = 1. Refuel (can reach pos 11).
- Fly to pos 6, then pos 11. Refuel at pos 11 (can reach pos 21).
- Fly to pos 20. Gas station at 20 is available. Refuel (can reach pos 30).
- Fly to pos 30. Refuel at pos 30 (can reach pos 40).
- Reach pos 40 via flying (fuel runs out at 40). Walk remaining distance from 40 to 42 (2 units).
- Total walk = 1 + 2 = 3 units (Note: adjusted based on reach checks).

## Function Template (Python 3)
class Solution:
    def minTotalWalk(self, n: int, gasStations: list[int]) -> int:
        # TODO: Implement your solution here
        pass

## Function Template (C++)
#include <vector>

class Solution {
public:
    int minTotalWalk(int n, std::vector<int>& gasStations) {
        // TODO: Implement your solution here
        return 0;
    }
};