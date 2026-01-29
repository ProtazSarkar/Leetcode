class Solution {
public:
    int minimumMoves(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ) {   // remove i++
            if (s[i] == 'X') {
                count++;
                i += 3;   // correct jump
            } else {
                i++;
            }
        }
        return count;
    }
};