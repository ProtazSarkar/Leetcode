# 3Sum With Multiplicity

**LeetCode 923**

## Problem Statement

Given an integer array `arr` and an integer `target`, count the number of
triplets of indices `(i, j, k)` such that:

```text
0 <= i < j < k < arr.length
arr[i] + arr[j] + arr[k] == target
```

Different index triplets count separately, even when some or all of their
values are equal. Return the count modulo `10⁹ + 7`.

### Example

```text
Input:  arr = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5], target = 8
Output: 20
```

## Approach: Frequency Counting

The values in `arr` are between `0` and `100`, so first count the occurrences
of every possible value. Then iterate over candidate values `i` and `j` with
`i <= j`, and calculate the third value:

```text
k = target - i - j
```

Only value triples in sorted order (`i <= j <= k`) are counted. This avoids
counting the same value combination more than once. For each valid triple,
the number of index combinations depends on whether its values repeat:

| Value relationship | Number of index triplets |
|---|---:|
| `i == j == k` | `C(count[i], 3)` |
| `i == j < k` | `C(count[i], 2) * count[k]` |
| `i < j == k` | `count[i] * C(count[j], 2)` |
| `i < j < k` | `count[i] * count[j] * count[k]` |

The combinations use distinct indices, as required. Accumulate each
contribution modulo `10⁹ + 7`.

## C++ Implementation

```cpp
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const long long MOD = 1'000'000'007;
        vector<long long> count(101, 0);

        for (int value : arr) {
            count[value]++;
        }

        long long answer = 0;

        for (int i = 0; i <= 100; i++) {
            if (count[i] == 0) {
                continue;
            }

            for (int j = i; j <= 100; j++) {
                if (count[j] == 0) {
                    continue;
                }

                int k = target - i - j;
                if (k < j || k > 100 || count[k] == 0) {
                    continue;
                }

                if (i == j && j == k) {
                    answer += count[i] * (count[i] - 1) *
                              (count[i] - 2) / 6;
                } else if (i == j) {
                    answer += count[i] * (count[i] - 1) / 2 * count[k];
                } else if (j == k) {
                    answer += count[i] * count[j] * (count[j] - 1) / 2;
                } else {
                    answer += count[i] * count[j] * count[k];
                }

                answer %= MOD;
            }
        }

        return static_cast<int>(answer);
    }
};
```

## Complexity

Let `U` be the number of possible values (`101` for this problem).

- **Time:** `O(n + U²)` — build the frequency table in `O(n)` and examine
  candidate value pairs in `O(U²)`.
- **Space:** `O(U)` — the frequency table stores one count per possible value.
