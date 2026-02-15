# LeetCode 240 – Search a 2D Matrix II

## 🧩 Problem Description

Given an $m \times n$ integer `matrix` and an integer `target`, return `true` if `target` is in the matrix, and `false` otherwise.

The matrix has the following properties:
* Integers in each row are sorted in ascending from left to right.
* Integers in each column are sorted in ascending from top to bottom.

---

## 🔍 Key Observations

* **Row-wise Sorted**: Each row is a valid candidate for a standard Binary Search.
* **Column-wise Sorted**: The vertical structure also follows a strict order, meaning if `matrix[i][j] > target`, every element below it in the same column is also greater than the target.
* **Decision Points**: Starting from the **Top-Right** or **Bottom-Left** corners allows for a binary decision (move left/right or up/down) at every step.

---

## 🧠 Approaches

### 1️⃣ Brute Force (Linear Scan)

#### 💡 Idea
Iterate through every single element in the $m \times n$ matrix until the target is found.

#### ⏱ Complexity
* **Time Complexity**: $O(m \cdot n)$ — Must check every element in the worst case.
* **Space Complexity**: $O(1)$ — No extra space used.
* **Verdict**: ❌ **Inefficient**. Does not take advantage of the sorted properties.

---

### 2️⃣ Row-by-Row Binary Search

#### 💡 Idea
Since each row is sorted, we can iterate through the rows and perform a **Binary Search** on each one.

#### 🛠 Algorithm
1.  Loop through each row $i$ from $0$ to $m-1$.
2.  Check if `target` falls within the range of the row: `matrix[i][0] <= target <= matrix[i][n-1]`.
3.  If it does, perform a recursive or iterative binary search on that row.


#### ⏱ Complexity
* **Time Complexity**: $O(m \cdot \log n)$ — Binary search $\log n$ performed $m$ times.
* **Space Complexity**: $O(\log n)$ — If implemented recursively (stack depth).
* **Verdict**: ⚠️ **Passes**, but sub-optimal as it ignores the column-wise sorting.

---

### 3️⃣ Optimized Approach (Staircase Search)

#### 💡 Idea
Start at the **Top-Right** corner $(0, n-1)$. At this position, we can eliminate either a full row or a full column in a single step.


#### 🛠 Algorithm
1.  Initialize `i = 0` (first row) and `j = n - 1` (last column).
2.  **While** within matrix boundaries:
    * If `matrix[i][j] == target`: Return `true`.
    * If `matrix[i][j] > target`: The target must be in a smaller column. Decrement `j` (**Move Left**).
    * If `matrix[i][j] < target`: The target must be in a larger row. Increment `i` (**Move Down**).
3.  If the loop finishes without a match, return `false`.

#### ⏱ Complexity
* **Time Complexity**: $O(m + n)$ — In the worst case, you travel from one corner to the opposite corner.
* **Space Complexity**: $O(1)$ — Purely iterative with no extra storage.
* **Verdict**: 🚀 **Optimal**.

---

## 📊 Comparison Summary

| Approach | Technique | Time Complexity | Space Complexity | Suitable |
| :--- | :--- | :--- | :--- | :--- |
| **Brute Force** | Linear Scan | $O(m \cdot n)$ | $O(1)$ | ❌ Slow |
| **Binary Search** | Row-by-Row | $O(m \cdot \log n)$ | $O(\log n)$ | ✅ Passes |
| **Staircase Search** | Search from Corner | $O(m + n)$ | $O(1)$ | 🚀 Optimal |

---

## Final Notes

* **Corner Selection**: You can also start at the **Bottom-Left** corner. However, starting at Top-Left or Bottom-Right doesn't work because both possible moves (right/down or left/up) would change the value in the same direction (both increase or both decrease).
* **Data Types**: For very large matrices, ensure your indices are `int` or `long` depending on the language constraints.

Happy coding 🚀
