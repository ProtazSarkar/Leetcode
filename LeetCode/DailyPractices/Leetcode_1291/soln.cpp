#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
        
        // Length of the sequential number
        for (int len = 1; len <= 9; ++len) {
            // Starting position in the string
            for (int i = 0; i <= 9 - len; ++i) {
                int num = stoi(s.substr(i, len));
                
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        
        // Ensure the result is sorted (which it naturally is with this approach)
        return ans;
    }
};