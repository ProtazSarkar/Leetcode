# Beautiful Array

**LeetCode 932**

## Problem

For a positive integer `n`, construct an array containing each integer from
`1` to `n` exactly once such that for every `i < j < k`:

```text
2 * nums[j] != nums[i] + nums[k]
```

In other words, no element between two other elements in the array can be
their arithmetic mean.

For example, for `n = 5`, `[1, 5, 3, 2, 4]` is beautiful: no element is the
average of two elements that appear on either side of it.

## Solution Approach: Recursively Separate Odd and Even Values

The solution builds a beautiful array for `n` from smaller beautiful arrays:

1. Recursively construct a beautiful array for `ceil(n / 2)`.
2. Recursively construct a beautiful array for `floor(n / 2)`.
3. Transform the first result into odd values using `2 * x - 1`.
4. Transform the second result into even values using `2 * x`.
5. Concatenate the odd values before the even values.

For example, when `n = 5`, the recursive results are transformed into:

```text
odd values:  [1, 3, 2] -> [1, 5, 3]
even values: [1, 2]    -> [2, 4]
result:      [1, 5, 3, 2, 4]
```

### Why the Construction Works

The base case `[1]` is beautiful because it contains no triple of indices.
Assume each recursive result is beautiful.

- **Triples contained in one group:** The transformations `2 * x - 1` and
  `2 * x` preserve the property. If a transformed middle value were the
  average of two transformed values, reversing the transformation would
  imply the same invalid triple existed in the smaller array.
- **Triples spanning both groups:** All odd values are placed before all even
  values. If the two endpoints have different parity, their sum is odd, while
  twice the middle value is even, so equality is impossible. If the endpoints
  have the same parity, they are in the same group; every index between them
  is also in that group, where the recursive result guarantees the property.

The transformations also produce exactly the required values: odd numbers
from `1` through `n`, followed by even numbers from `1` through `n`.

## C++ Implementation

```cpp
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) {
            return {1};
        }

        vector<int> odd = beautifulArray((n + 1) / 2);
        vector<int> even = beautifulArray(n / 2);

        vector<int> answer;
        answer.reserve(n);

        for (int x : odd) {
            answer.push_back(2 * x - 1);
        }
        for (int x : even) {
            answer.push_back(2 * x);
        }

        return answer;
    }
};
```

## Complexity

- **Time:** `O(n log n)`. At each recursion level, the transformation and
  concatenation process handles `n` total elements. The recursive subproblem
  sizes are approximately halved, giving `O(log n)` levels.
- **Space:** `O(n)` peak space, including the returned array and temporary
  arrays kept during recursion.
