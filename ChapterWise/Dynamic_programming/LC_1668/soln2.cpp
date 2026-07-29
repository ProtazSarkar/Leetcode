#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.length();
        int m = word.length();
        int max_repeat = 0;
        
        for (int i = 0; i <= n - m; ++i) {
            int count = 0;
            // Check consecutive occurrences starting from index i
            while (i + (count + 1) * m <= n && 
                   sequence.substr(i + count * m, m) == word) {
                count++;
            }
            max_repeat = std::max(max_repeat, count);
        }
        
        return max_repeat;
    }
};