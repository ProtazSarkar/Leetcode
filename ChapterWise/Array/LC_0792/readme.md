# Number of Matching Subsequences

**LeetCode 792**

## Problem Statement

Given a string `s` and an array of strings `words`, return the number of words that are subsequences of `s`.

A string `word` is a subsequence of `s` if there exists a sequence of indices in `s` such that `word` can be formed by selecting characters from `s` in order, without changing their relative order.

## Approach

Instead of checking each word against `s` from scratch, we optimize the process by precomputing character positions.

### Key Idea

- Store all indices of each character from `a` to `z` in `char_indices`.
- For each word, scan its characters left to right.
- For every character, use binary search (`upper_bound`) to find the next occurrence in `s` that is strictly greater than the previous match index.
- If a character cannot be found, the word is not a subsequence.

This reduces repeated searching to a logarithmic lookup per character instead of repeated linear scans.

## C++ Implementation

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;

        vector<vector<int>> char_idxs(26);
        for (int i = 0; i < s.length(); ++i) {
            char_idxs[s[i] - 'a'].push_back(i);
        }

        for (const string& w : words) {
            int curr_idx = -1;
            bool is_sub = true;

            for (char c : w) {
                const vector<int>& idxs = char_idxs[c - 'a'];
                auto it = upper_bound(idxs.begin(), idxs.end(), curr_idx);
                if (it == idxs.end()) {
                    is_sub = false;
                    break;
                }
                curr_idx = *it;
            }

            if (is_sub) {
                ++count;
            }
        }

        return count;
    }
};
```

## Complexity

- **Time:** `O(|s| + total_words * average_word_length * log |s|)`
- **Space:** `O(|s|)` for storing the character-index mapping.