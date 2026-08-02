# Trapping Rain Water - Maximum Element Split Approach

This C++ solution solves the classic **Trapping Rain Water** problem (LeetCode 42) by first locating the highest peak in the elevation map and then evaluating the left and right slopes independently.

---

## 💡 Core Intuition

Instead of using a two-pointer approach that moves dynamically inward, this strategy splits the problem into two distinct halves based on the **global maximum height**:

1. **Find the Peak:** Locate the index of the tallest bar (`max_idx`) in the entire array. This highest bar acts as a reliable absolute boundary.
2. **Left Slope (`0` to `max_idx`):** Traverse from left to right up to the peak. Because the global maximum lies at or beyond `max_idx`, any bar to its left is guaranteed to be bounded by a taller wall to its right (the peak itself).
3. **Right Slope (`n-1` down to `max_idx`):** Traverse from right to left back toward the peak. Similarly, any bar in this section is guaranteed to be bounded by a taller wall to its left.

---

## 🛠️ Step-by-Step Breakdown

### 1. Boundary & Peak Detection
```cpp
int n = height.size();
if(n <= 2) {
    return 0;
}
int ans = 0;
int left_max = 0, right_max = 0;

int max_idx = 0;
for(int i = 0; i < n; i++) {
    if(height[i] > height[max_idx]) {
        max_idx = i;
    }
}