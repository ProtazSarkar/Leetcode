#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    // Helper function to count subarrays with AT MOST k distinct elements
    int atMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        unordered_map<int, int> countMap;
        int left = 0, totalSubarrays = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // Add the current element to our window
            countMap[nums[right]]++;
            
            // If we have more than k distinct elements, shrink from the left
            while (countMap.size() > k) {
                countMap[nums[left]]--;
                if (countMap[nums[left]] == 0) {
                    countMap.erase(nums[left]);
                }
                left++;
            }
            
            // Key formula: The number of valid subarrays ending at 'right' 
            // is equal to the size of the current window.
            totalSubarrays += (right - left + 1);
        }
        
        return totalSubarrays;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exact(K) = AtMost(K) - AtMost(K - 1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};