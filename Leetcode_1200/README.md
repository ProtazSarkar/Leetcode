# LeetCode 1200: Minimum Absolute Difference

## 📝 Problem Description
Given an array of **distinct** integers `arr`, find all pairs of elements with the minimum absolute difference of any two elements. 

The output should be a list of pairs in ascending order, where each pair `[a, b]` satisfies:
- `a < b`
- `b - a == min_difference`

## 💡 Intuition
In an unsorted array, the two numbers with the minimum difference could be anywhere. However, once the array is **sorted**, the two numbers with the smallest gap **must** be adjacent to each other. This reduces the problem from checking every possible combination $O(n^2)$ to just checking neighbors $O(n)$.



## 🛠️ Approach
1. **Sort**: Arrange the array in ascending order using `std::sort`.
2. **Initialize**: Set `min_diff` to a very large value (`INT_MAX`) and create an empty list for pairs.
3. **Traverse**: Iterate through the array from `0` to `n-2`:
    - Calculate `diff = arr[i+1] - arr[i]`.
    - If `diff < min_diff`:
        - Update `min_diff`.
        - Clear the current list of pairs.
        - Add the new pair `{arr[i], arr[i+1]}`.
    - Else if `diff == min_diff`:
        - Add the pair `{arr[i], arr[i+1]}` to the existing list.
4. **Return**: The list of pairs is already in ascending order because we processed the sorted array from left to right.

## 📊 Complexity Analysis
- **Time Complexity**: $O(n \log n)$ 
  - Sorting the array takes $O(n \log n)$.
  - The subsequent linear scan takes $O(n)$.
- **Space Complexity**: $O(\log n)$
  - This is the space used by the sorting algorithm (stack space for Quicksort/Introsort). 
  - Note: The output list space is usually not counted toward auxiliary space complexity.
