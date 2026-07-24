#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        string t = "1" + s + "1";
        
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }
        
        // Parse t into segments of zeros and ones
        vector<int> zero_lengths;
        int i = 0;
        while (i < t.length()) {
            if (t[i] == '1') {
                i++;
            } else {
                int j = i;
                while (j < t.length() && t[j] == '0') {
                    j++;
                }
                zero_lengths.push_back(j - i);
                i = j;
            }
        }
        
        // If there are fewer than 2 zero blocks in the augmented string, 
        // we can't bridge two zero blocks by removing an internal '1' block.
        int max_gain = 0;
        for (size_t k = 1; k < zero_lengths.size(); ++k) {
            max_gain = max(max_gain, zero_lengths[k - 1] + zero_lengths[k]);
        }
        
        return total_ones + max_gain;
    }
};