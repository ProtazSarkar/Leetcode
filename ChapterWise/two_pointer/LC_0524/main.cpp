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
    bool is_subSeq(string a, string b) {
        // a is the main string, b is the substring/candidate
        int n = a.length(), m = b.length();
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (a[i] == b[j]) {
                j++;
            }
            i++;
        }
        return m == j;
    }

public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // Custom comparator:
        // 1. Longer length comes first (descending).
        // 2. If lengths are equal, lexicographically smaller string comes first (ascending).
        auto cmp = [](const string& s1, const string& s2) {
            if (s1.length() == s2.length()) {
                return s1 < s2; // Standard lexicographical order
            }
            return s1.length() > s2.length(); // Longer string first
        };

        // Fix: corrected spelling from 'dicitonary' to 'dictionary'
        sort(dictionary.begin(), dictionary.end(), cmp);

        // Fix: corrected spelling from 'stirng' to 'string'
        for (const string& sub : dictionary) {
            if (is_subSeq(s, sub)) {
                return sub;
            }
        }

        return "";
    }
};