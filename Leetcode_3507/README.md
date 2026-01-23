# LeetCode 3507 – Minimum Pair Removal to Make Array Non-Decreasing

## Problem Statement

Given an array `nums`, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in `nums`. If multiple such pairs exist, choose the leftmost one. Replace the selected pair with their sum.

Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

---

## Key Observation

Each operation reduces the size of the array by exactly one. Merging two adjacent elements can reduce local disorder in the array. Repeating this process eventually leads to a non-decreasing array. The brute-force approach simulates the process exactly as described in the problem without applying any optimizations.

---

## Approach: Brute Force Simulation

The brute-force approach repeatedly applies the given operation until the array becomes non-decreasing. In each step, the algorithm scans the entire array to identify the adjacent pair with the minimum sum. If multiple such pairs exist, the leftmost one is selected. That pair is then replaced with their sum, and the process is repeated.

This approach guarantees correctness because it strictly follows the rules defined in the problem statement, but it is computationally expensive due to repeated full scans of the array.

---

## Algorithm

First, copy the input array into a working array. Check whether the array is already non-decreasing. If it is not, scan all adjacent pairs to determine the pair with the minimum sum, prioritizing the leftmost pair in case of a tie. Replace the selected pair with their sum, reducing the array size by one. Increment the operation counter and repeat the process until the array becomes non-decreasing. Finally, return the total number of operations performed.

---

## Example

Consider the array `nums = [5, 3, 2, 4]`. The adjacent sums are 8, 5, and 6. The minimum sum is obtained from the pair (3, 2), which is replaced by 5, resulting in the array [5, 5, 4]. The array is still not non-decreasing. In the next step, the adjacent sums are 10 and 9. The pair (5, 4) is replaced by 9, resulting in the array [5, 9], which is non-decreasing. Therefore, the minimum number of operations required is 2.

---

## Time Complexity

Checking whether the array is non-decreasing requires a full scan of the array, which takes linear time. Finding the adjacent pair with the minimum sum also requires a linear scan. Rebuilding the array after each merge operation takes linear time as well. Since up to a linear number of merge operations may be required, the overall time complexity of the brute-force approach is cubic in the size of the array.

Overall time complexity: O(n³)

---

## Space Complexity

Additional space is required to store the modified array after each merge operation. The space complexity of the brute-force approach is linear with respect to the size of the array.

Overall space complexity: O(n)

---

## Notes

This brute-force solution is easy to understand and directly mirrors the problem description. It is useful for learning, debugging, and validating logic, but it is not suitable for large inputs due to its high time complexity and may result in a time limit exceeded error on competitive programming platforms.

---

## File Structure

bruteforce.cpp – Brute-force simulation implementation  
README.md – Problem description and brute-force analysis