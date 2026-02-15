class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Keep going as long as there are digits or a leftover carry
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i] - '0'; // Quick char to int conversion
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            carry = sum / 2;      // Calculate new carry
            ans += (sum % 2) + '0'; // Calculate bit and convert to char
        }

        reverse(ans.begin(), ans.end()); // Since we added bits to the end
        return ans;
    }
};
