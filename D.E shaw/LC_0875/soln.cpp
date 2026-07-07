#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    // Helper to calculate ceil(pile / k) safely
    long long get_hours_for_pile(int pile, int k) {
        if (k == 0) return 1e18; // Safety guard, though mid won't be 0 now
        return (pile + k - 1) / k; 
    }

    bool is_possible(vector<int>& piles, int k, int h) {
        long long total_hr = 0;
        for (int pile : piles) {
            total_hr += get_hours_for_pile(pile, k);
        }
        return total_hr <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // The minimum possible speed is 1 banana per hour
        int left = 1; 
        
        // The maximum useful speed is the size of the largest pile
        int right = 0;
        for (int pile : piles) {
            right = max(right, pile);
        }

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (is_possible(piles, mid, h)) {
                ans = mid;        // mid is a valid speed, record it
                right = mid - 1;  // Try to find a slower valid speed
            } else {
                left = mid + 1;   // Too slow! We need a faster speed
            }
        }

        return ans;
    }
};