#include <iostream>
#include <sstream>

// Containers
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for(int num : nums){
            ones = (num ^ ones) & ~twos;
            twos = (num ^ twos) & ~ones;
        }
        return ones;
    }
};