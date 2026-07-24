# LeetCode 3507 – Minimum Pair Removal to Make Array Non-Decreasing

## Problem Statement

You are given an integer array `nums`.

You can perform the following operation any number of times:

- Select the **adjacent pair with the minimum sum**
- If multiple such pairs exist, choose the **leftmost** one
- Replace the selected pair with their **sum**

Return the **minimum number of operations** required to make the array **non-decreasing**.

An array is **non-decreasing** if  
`nums[i] >= nums[i - 1]` for all valid `i`.

---

## Key Observations

- Each operation reduces the array size by **one**
- Only **local inversions** (`a[i] > a[i+1]`) matter
- Repeatedly merging the **minimum-sum adjacent pair** eventually removes all inversions
- The challenge is doing this **efficiently**

---

## Approach 1: Brute Force Simulation

### Idea

This approach directly follows the problem statement without any optimization.

At every step:
- Scan all adjacent pairs
- Find the minimum sum (choose leftmost on tie)
- Merge the pair
- Repeat until the array becomes non-decreasing

---

### Brute Force Algorithm

1. Copy `nums` into a working array
2. While the array is **not non-decreasing**:
   - Scan all adjacent pairs to find the minimum sum
   - Merge the leftmost pair with that sum
   - Increment operation counter
3. Return the operation count

---

### Example

Input: `[5, 3, 2, 4]`

- Adjacent sums → `8, 5, 6`
- Merge `(3,2)` → `[5, 5, 4]`
- Adjacent sums → `10, 9`
- Merge `(5,4)` → `[5, 9]`

Output: `2`

---

### Complexity

- Sorted check: `O(n)`
- Min pair scan: `O(n)`
- Merge cost: `O(n)`
- Up to `O(n)` merges

**Time Complexity:** `O(n³)`  
**Space Complexity:** `O(n)`

---

### Limitation

- Easy to understand
- Too slow for large inputs
- Causes **TLE**

---

## Approach 2: Optimized (Vector + Min Heap + Bad Index Set)

### Core Idea

Instead of rescanning the entire array:
- Track only **where the array is decreasing**
- Always merge the **minimum valid adjacent sum**
- Update only **local regions** after a merge

---

### Data Structures

1. `vector<long long> arr`  
   - Stores current array

2. `set<int> bad`  
   - Stores indices `i` where `arr[i] > arr[i+1]`
   - If empty → array is non-decreasing

3. Min Heap (`priority_queue`)
   - Stores `{sum, index}`
   - Lazy deletion handles outdated pairs

---

### Algorithm Steps

1. Initialize `arr`, `bad`, and heap with all adjacent sums
2. While `bad` is not empty:
   - Extract a valid minimum-sum pair
   - Merge the pair
   - Remove affected indices from `bad`
   - Recheck local order
   - Push new adjacent sums
3. Return the operation count

---

### Complexity

- Heap operations: `O(log n)`
- At most `n-1` merges

**Time Complexity:** `O(n log n)`  
**Space Complexity:** `O(n)`

---

### Notes

- Faster than brute force
- Needs careful handling of stale heap entries
- Index shifting adds complexity

---

## Approach 3: Optimized (List + Set + Iterators)

### Core Idea

This approach avoids index shifting entirely by using:
- A **doubly linked list** for merges
- A **sorted set of adjacent sums**
- Iterators to directly access neighbors

---

### Data Structures

1. `list<long long> arr`
   - Allows `O(1)` merge and erase

2. `set<{sum, iterator}>`
   - Sorted by sum
   - Iterator points to left element of the pair
   - Custom comparator breaks ties safely using addresses

---

### Algorithm Steps

1. Initialize the list and insert all adjacent pair sums into the set
2. Repeat until the array is non-decreasing:
   - Check sorted order by single traversal
   - Extract minimum-sum adjacent pair
   - Remove outdated neighboring pairs
   - Merge the selected pair
   - Insert newly formed adjacent pairs
   - Increment operation count
3. Return the operation count

---

### Complexity

- Each merge: `O(log n)` set operations + `O(1)` list operations
- At most `n-1` merges

**Time Complexity:** `O(n log n)`  
**Space Complexity:** `O(n)`

---

### Advantages

- No index shifting
- Clean iterator-based logic
- Fully STL-compliant
- Very stable and readable

---

## Comparison Summary

| Approach | Technique | Time | Space | Suitable |
|--------|----------|------|-------|----------|
| Brute Force | Full simulation | O(n³) | O(n) | ❌ |
| Heap + Vector | Lazy heap + indices | O(n log n) | O(n) | ✅ |
| List + Set | Iterators + ordered set | O(n log n) | O(n) | ✅ |

---

## Files

- `bruteforce.cpp` – Brute force solution  
- `heap_solution.cpp` – Vector + heap + bad-index approach  
- `solution.cpp` – List + set optimized solution  
- `README.md` – Complete explanation (this file)

---

## Final Notes

- Brute force helps understand the mechanics
- Heap approach improves performance with index tracking
- List-based approach is the cleanest and safest
- Keeping all three makes the README **educational and professional**

Happy coding 🚀