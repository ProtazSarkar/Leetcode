class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        
        int ans = 10;          // Covers n = 1 (numbers 0 to 9)
        int uniqueDigits = 9;  
        int availableNum = 9;  
        
        // Sum up unique digit numbers for lengths 2 up to n
        while (n > 1 && availableNum > 0) {
            uniqueDigits *= availableNum;
            ans += uniqueDigits;
            n--;
            availableNum--;
        }
        
        return ans;
    }
};