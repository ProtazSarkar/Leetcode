# Number of Boomerangs

**LeetCode 447**

## Problem Statement

Given a set of distinct points on a plane, count the number of boomerangs.
A boomerang is an ordered tuple of points `(i, j, k)` such that the distance
from `i` to `j` is equal to the distance from `i` to `k`.

The points `j` and `k` must be different from each other and from `i`.
Because the tuple is ordered, `(i, j, k)` and `(i, k, j)` are counted as
different boomerangs.

### Example

```text
Input:  points = [[0, 0], [1, 0], [2, 0]]
Output: 2
```

Using `[1, 0]` as the center, the two outer points are both one unit away.
They can be assigned to `j` and `k` in two orders.

## Approach: Group Points by Squared Distance

Fix each point `i` as the center. For every other point `j`, calculate the
squared Euclidean distance:

```text
distanceSquared = (x_i - x_j)² + (y_i - y_j)²
```

Squared distance is sufficient because comparing squared distances gives the
same result as comparing distances, without needing to calculate square roots.

Count how many points are at each squared distance from the center. If `m`
points share a distance, there are `m` choices for `j` and `m - 1` remaining
choices for `k`. Therefore, this distance group contributes:

```text
m * (m - 1)
```

This counts both possible orders for each pair. Repeat for every center and
sum the contributions.

## C++ Implementation

```cpp
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int answer = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> frequency;

            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int distanceSquared = dx * dx + dy * dy;

                frequency[distanceSquared]++;
            }

            for (const auto& [distanceSquared, count] : frequency) {
                answer += count * (count - 1);
            }
        }

        return answer;
    }
};
```

## Complexity

- **Time:** `O(n²)` expected — for each of the `n` centers, distances to the
  other points are counted in a hash map.
- **Space:** `O(n)` — the frequency map stores at most one entry per other
  point for the current center.
