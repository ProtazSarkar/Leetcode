#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool solve(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return false; // Must have at least 3 elements to split into 3 non-empty parts

    int c1 = 0, c2 = 0, c3 = 0;
    int min_f_val = INT_MAX; 
    bool found_valid_part1 = false;

    // We loop up to n-2 because Part 3 must have at least 1 element at the end (nums[n-1])
    for (int j = 0; j < n - 1; j++) {
        // Update total counts up to the current index
        if (nums[j] == 1) c1++;
        else if (nums[j] == 2) c2++;
        else if (nums[j] == 3) c3++;

        // 1. Check if the prefix up to 'j' forms a valid Part 1
        // Condition: ones >= twos + threes  ==>  2 * c1 >= total elements
        if (2 * c1 >= (j + 1)) {
            int current_f = 2 * (c1 + c2) - (j + 1);
            min_f_val = min(min_f_val, current_f);
            found_valid_part1 = true;
        }

        // 2. Check if the current index 'j' can close a valid Part 2
        // We can only check this if we have at least one valid Part 1 behind us
        if (found_valid_part1) {
            int current_f = 2 * (c1 + c2) - (j + 1);
            
            // If the current balance is >= the minimum balance of a valid Part 1, 
            // a valid Part 2 exists between that Part 1 endpoint and today's index 'j'.
            if (current_f >= min_f_val && j > 0) { 
                // Since j < n-1, Part 3 is guaranteed to be non-empty (at least includes nums[n-1])
                return true; 
            }
        }
    }

    return false;
}