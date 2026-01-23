# LeetCode 3507 – Minimum Pair Removal to Make Array Non-Decreasing

## Problem Statement

You are given an integer array `nums`.

You can perform the following operation any number of times:

- Select the **adjacent pair with the minimum sum**.
- If multiple such pairs exist, choose the **leftmost** one.
- Replace the selected pair with their **sum**.

Return the **minimum number of operations** required to make the array **non-decreasing**.

An array is **non-decreasing** if  
`nums[i] >= nums[i - 1]` for all valid `i`.

---

## Key Insight

- Each operation **reduces the array size by exactly one**
- Only **local inversions** (`arr[i] > arr[i+1]`) prevent the array from being sorted
- Repeatedly merging the minimum-sum adjacent pair eventually removes all inversions

---

## Approach 1: Brute Force Simulation

### Idea

This approach follows the problem statement **exactly as written**, without any optimization.

At each step:
- Scan the array to find the **minimum adjacent sum**
- Choose the **leftmost** such pair
- Merge the pair
- Repeat until the array becomes non-decreasing

This method is simple and good for understanding the problem logic.

---

### Brute Force Algorithm

1. Copy `nums` into a working array
2. While the array is **not non-decreasing**:
   - Scan all adjacent pairs to find the minimum sum
   - If multiple pairs have the same sum, pick the leftmost one
   - Replace that pair with their sum
   - Increment the operation counter
3. Return the operation count

---

### Brute Force Example

**Input:**  
`nums = [5, 3, 2, 4]`

- Adjacent sums → `8, 5, 6`
- Minimum sum → `(3,2)`
- Array becomes → `[5, 5, 4]`

Still decreasing.

- Adjacent sums → `10, 9`
- Minimum sum → `(5,4)`
- Array becomes → `[5, 9]`

Now non-decreasing.

**Output:** `2`

---

### Brute Force Complexity

- Checking sorted order: `O(n)`
- Finding minimum adjacent sum: `O(n)`
- Array rebuild per merge: `O(n)`
- Up to `O(n)` merges

**Time Complexity:** `O(n³)`  
**Space Complexity:** `O(n)`

---

### Brute Force Limitation

- Works correctly
- Easy to implement
- **Too slow for large inputs**
- Causes **TLE** on competitive platforms

---

## Approach 2: Optimized Simulation (Heap + Set)

### Core Idea

Instead of rescanning the whole array every time:
- Track **only where the array is decreasing**
- Always extract the **minimum adjacent sum** efficiently
- Update **only local changes** after each merge

---

### Data Structures Used

1. **Dynamic Array (`vector<long long>`)**
   - Stores the current array after merges

2. **Set (`set<int> bad`)**
   - Stores indices `i` where `arr[i] > arr[i+1]`
   - If empty → array is non-decreasing

3. **Min Heap (`priority_queue`)**
   - Stores `{sum, index}` for adjacent pairs
   - Always provides the minimum adjacent sum
   - Uses **lazy deletion** to discard outdated entries

---

### Optimized Algorithm (Step-by-Step)

#### Step 1: Initialization
- Copy `nums` into `arr`
- Identify all decreasing indices and store them in `bad`
- Push all adjacent pair sums into the min heap

---

#### Step 2: Fix Disorder
Repeat while `bad` is not empty:

1. **Extract a valid minimum pair**
   - Pop heap elements until the index is valid
   - Ensure the stored sum matches the current adjacent sum

2. **Merge the pair**
   - Replace `arr[idx]` with `arr[idx] + arr[idx+1]`
   - Remove `arr[idx+1]`
   - Increment operation count

3. **Update disorder (`bad` set)**
   - Remove affected indices: `idx-1`, `idx`, `idx+1`
   - Recheck local order and reinsert violations if needed

4. **Push new adjacent sums**
   - Push `(arr[idx-1] + arr[idx])` if valid
   - Push `(arr[idx] + arr[idx+1])` if valid

---

#### Step 3: Termination
- When `bad` becomes empty, the array is non-decreasing
- Return the operation count

---

### Optimized Example

**Input:**  
`nums = [5, 3, 2, 4]`

- Minimum adjacent sum `(3,2)` → merge → `[5,5,4]`
- Minimum adjacent sum `(5,4)` → merge → `[5,9]`
- Array becomes non-decreasing

**Output:** `2`

---

### Optimized Complexity

- Heap operations: `O(log n)`
- At most `n-1` merges

**Time Complexity:** `O(n log n)`  
**Space Complexity:** `O(n)`

---

## Comparison Summary

| Approach        | Time Complexity | Space | Suitable for Large Inputs |
|-----------------|-----------------|-------|---------------------------|
| Brute Force     | O(n³)           | O(n)  | ❌ No                     |
| Optimized Heap  | O(n log n)      | O(n)  | ✅ Yes                    |

---

## Files

- `solution.cpp` – Optimized solution using heap and set  
- `bruteforce.cpp` – Brute force simulation  
- `README.md` – Complete explanation (this file)

---

## Final Notes

- Brute force is excellent for **learning and validation**
- Optimized solution is required for **real constraints**
- Both together make this README **clear, complete, and professional**

Happy coding 🚀