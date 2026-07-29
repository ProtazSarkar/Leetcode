#include <string>
using namespace std;


class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string repeating = word;
        
        // Keep appending word and checking if it's a substring
        while (sequence.find(repeating) != string::npos) {
            ans++;
            repeating += word;
        }
        
        return ans;
    }
};