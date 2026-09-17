Find Two Non-Overlapping Sub-arrays Each With Target Sum
Problem Statement
Given an array of integers arr and an integer target, you need to find two non-overlapping sub-arrays of arr such that the sum of values in each sub-array is equal to the target.

The goal is to find the minimum possible sum of the lengths of these two sub-arrays. If no such two non-overlapping sub-arrays exist, return -1.

Why a Greedy Approach Fails
A common intuition is to use a sliding window, and the moment a valid sub-array is found, greedily reset the window to look for the next one. However, this fails because:

Greedy skips options: Immediately locking in a sub-array can block overlapping or nested sub-arrays that might yield better lengths.

Overlap management: A simple priority queue or heap only tracks lengths, not where those sub-arrays live. It cannot guarantee that the two shortest sub-arrays found across the entire array are strictly non-overlapping.

The Optimal Approach (Dynamic Programming + Sliding Window)
To solve this efficiently in linear time, we combine a sliding window with a prefix minimum tracking array.

Step-by-Step Algorithm:
Track Prefix Minimums (minLen array): Create an array minLen of size n initialized to infinity. minLen[i] will store the length of the shortest valid sub-array (sum equal to target) found anywhere in the prefix from index 0 up to index i.

Find Sub-arrays via Sliding Window: Use a standard two-pointer sliding window (left and right) to scan through the array:

Expand the window by adding arr[right] to sum.

Shrink the window from the left (sum -= arr[left++]) while sum > target.

Check for Non-Overlapping Pairs: When sum == target:

Calculate the current sub-array length: currLen = right - left + 1.

Check if there is a valid sub-array to its left by looking at minLen[left - 1]. If minLen[left - 1] is not infinity, we have found a valid pair of non-overlapping sub-arrays with a total length of currLen + minLen[left - 1].

Update our global minimum result (res).

Update Prefix State: Update minSoFar with the minimum length seen so far, and set minLen[right] = minSoFar.

Result: After checking the entire array, if res was updated, return res. Otherwise, return -1.

Complexity
Time Complexity: O(N) because the sliding window pointers (left and right) traverse the array at most once.

Space Complexity: O(N) to store the minLen tracking array.