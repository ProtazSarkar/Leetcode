# Solution: Construct Transformed Array (LeetCode 3379)

## Approach
The problem asks us to build a `result` array where each `result[i]` is determined by "jumping" from index `i` based on the value of `nums[i]`. 

1. **Calculate Target:** For each index `i`, the target landing position is calculated as `(i + nums[i])`. 
2. **Handle Circular Wrap:** Since the array is circular, we use the modulo operator. To handle negative jumps (moving left), we use the formula `(i + nums[i] % n + n) % n` to ensure the index stays within the valid range `[0, n-1]`.
3. **Assign Value:** We look at the value located at the `target` index in the original array and assign it to `result[i]`.



## Complexity
* **Time Complexity:** $O(n)$
We iterate through the `nums` array exactly once, performing constant time arithmetic for each element.

* **Space Complexity:** $O(n)$
We initialize a new `result` vector of size $n$ to store and return the transformed values.
