#include <iostream>
#include <sstream>

// Containers
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>

// Associative Containers (Trees/Hashes)
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

// Algorithms & Utilities
#include <algorithm>
#include <numeric>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.length();

        //step 1 find the pivot first character that is greater than its next character
        int i=len-2;
        while(i>=0 && s[i]>=s[i+1]){
            i--;
        }
        if(i < 0)  return -1;

        //step 2 find the smallest char on the right that is greater than the pivot
        int j=len-1;
        while(j>i && s[i]>=s[j]){
            j--;
        }

        //step 3 swap both chars
        swap(s[i],s[j]);

        //step 4 reverset the remaing parts of the string
        reverse(s.begin()+i+1,s.end());
        long long result = stoll(s);
        if(result > INT_MAX || result<=n){
            return -1;
        }
        return (int)result;
    }
};