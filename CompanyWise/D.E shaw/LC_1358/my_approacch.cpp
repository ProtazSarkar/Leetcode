#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count_a = 0, count_b = 0, count_c = 0;
        int ans = 0;
        
        int j = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a')   count_a++;
            if(s[i] == 'b')   count_b++;
            if(s[i] == 'c')   count_c++;

            // Using logical AND (&&) ensures we check if all counts are non-zero
            while(count_a > 0 && count_b > 0 && count_c > 0){
                ans += n - i;
                if(s[j] == 'a')   count_a--;
                if(s[j] == 'b')   count_b--;
                if(s[j] == 'c')   count_c--;
                j++;
            }
        }

        return ans;
    }
};