# Max Sum Trionic Subarray

An efficient Dynamic Programming solution to find the maximum sum of a **Trionic Subarray**.

## 📝 Problem Definition

A **Trionic Subarray** is a contiguous segment `nums[l...r]` characterized by an "N-shape" trend. It requires three distinct phases defined by indices $l < p < q < r$:

1.  **Strictly Increasing:** From index $l$ to $p$.
2.  **Strictly Decreasing:** From index $p$ to $q$.
3.  **Strictly Increasing:** From index $q$ to $r$.



The objective is to find the maximum possible sum of such a contiguous subarray.

---

## 🚀 The Approach: Finite State Machine (DP)

The solution uses a **State-Based Dynamic Programming** approach. We navigate through the array while maintaining a "trend state" to ensure the contiguous and strictness constraints are met.

### State Transitions

| State | Description | Transition Criteria |
| :--- | :--- | :--- |
| **0** | **Searching** | Can skip elements or pick `nums[i]` to start Leg 1. |
| **1** | **Leg 1 (Up)** | `nums[i] > nums[i-1]`. Can stay in Leg 1 or move to Leg 2. |
| **2** | **Leg 2 (Down)** | `nums[i] < nums[i-1]`. Can stay in Leg 2 or move to Leg 3. |
| **3** | **Leg 3 (Up)** | `nums[i] > nums[i-1]`. Can stay in Leg 3 or finish the subarray. |



### Complexity Analysis
* **Time Complexity:** $O(n)$ — Each index is visited for a constant number of states (4).
* **Space Complexity:** $O(n)$ — Used for the memoization table and recursion depth.

---

## 💻 Implementation

```cpp
class Solution {
    int n;
    const long long INF = 1e16;
    vector<vector<long long>> dp;

    long long solve(vector<int>& a, int i, int trend) {
        if (i == n) return (trend == 3 ? 0 : -INF);
        if (dp[i][trend] != -1) return dp[i][trend];

        long long ans = -INF;

        // STATE 0: Searching for starting point 'l'
        if (trend == 0) {
            ans = max(ans, solve(a, i + 1, 0)); 
            long long next = solve(a, i + 1, 1); 
            if (next != -INF) ans = max(ans, a[i] + next);
        }

        // STATE 1: Leg 1 (Strictly Increasing)
        else if (trend == 1) {
            if (a[i] > a[i-1]) {
                long long stay = solve(a, i + 1, 1);
                if (stay != -INF) ans = max(ans, a[i] + stay);
                long long move = solve(a, i + 1, 2);
                if (move != -INF) ans = max(ans, a[i] + move);
            }
        }

        // STATE 2: Leg 2 (Strictly Decreasing)
        else if (trend == 2) {
            if (a[i] < a[i-1]) {
                long long stay = solve(a, i + 1, 2);
                if (stay != -INF) ans = max(ans, a[i] + stay);
                long long move = solve(a, i + 1, 3);
                if (move != -INF) ans = max(ans, a[i] + move);
            }
        }

        // STATE 3: Leg 3 (Strictly Increasing)
        else if (trend == 3) {
            if (a[i] > a[i-1]) {
                long long stay = solve(a, i + 1, 3);
                if (stay != -INF) ans = max(ans, a[i] + stay);
                ans = max(ans, (long long)a[i]); 
            }
        }

        return dp[i][trend] = ans;
    }

public:
    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<long long>(4, -1));
        long long result = solve(nums, 0, 0);
        return (result < -1e14 ? -1 : result);
    }
};
