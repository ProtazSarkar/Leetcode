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
    string fractionToDecimal(int numerator, int denominator) {
        //base case 
        if(numerator == 0){
            return "0";
        }

        string result = "";
        if(numerator<0 ^ denominator<0){
            result.push_back('-');
        }

        long long num = abs(static_cast<long long>(numerator));
        long long den = abs(static_cast<long long>(denominator));

        result+= to_string(num/den);

        long long reminder = num % den;
        if(reminder == 0){
            return result;
        }

        result.push_back('.');

        unordered_map<long long , int> reminder_map;
        while(reminder != 0){
            if(reminder_map.find(reminder) != reminder_map.end()){
                int idx = reminder_map[reminder];
                result.insert(idx,"(");
                result.push_back(')');
                return result;
            }
            reminder_map[reminder] = result.length();
            reminder*=10;
            result+=to_string(reminder/den);
            reminder %= den;
        }

        return result;
    }
};