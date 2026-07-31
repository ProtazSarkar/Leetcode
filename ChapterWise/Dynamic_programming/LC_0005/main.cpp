#include <string>
#include <algorithm>

class Solution {
private:
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }

public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int max_len = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // Odd length palindrome (single character center)
            int len1 = expandAroundCenter(s, i, i);
            // Even length palindrome (between two characters center)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int current_max = std::max(len1, len2);
            if (current_max > max_len) {
                max_len = current_max;
                start = i - (current_max - 1) / 2;
            }
        }
        
        return s.substr(start, max_len);
    }
};