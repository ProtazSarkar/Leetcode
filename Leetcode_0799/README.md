# LeetCode 799 – Champagne Tower

## 🧩 Problem Description

We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row. Each glass holds exactly one cup of champagne. 

When champagne is poured into the topmost glass, any excess liquid falls equally onto the two glasses immediately below it (to the left and right). If those glasses fill up, their excess also spills equally to the glasses below them. 

Given a non-negative integer `poured`, return how full the $j^{th}$ glass of the $i^{th}$ row is (where $i$ and $j$ are 0-indexed).

---

## 🔍 Key Observations

* **Overflow Logic**: A glass only distributes liquid to the next row if its current volume exceeds **1.0**.
* **Equal Splitting**: The excess amount, calculated as $(\text{current volume} - 1.0) / 2.0$, is split exactly in half between the two glasses directly underneath.
* **DP State**: The state of any glass $(i, j)$ depends entirely on the overflow from the glass $(i-1, j)$ and $(i-1, j-1)$ in the row above.

---

## 🧠 Approaches

### 1️⃣ Simulation (2D Dynamic Programming)

#### 💡 Idea
We can simulate the pouring process row by row using a 2D matrix. Instead of trying to calculate where every drop goes simultaneously, we process the total "potential" liquid in each glass and pass the overflow down to the next level.



#### 🛠 Algorithm
1.  Initialize a 2D array `mat[101][101]` with zeros.
2.  Set the top glass `mat[0][0]` to the total amount `poured`.
3.  Iterate through each row `i` up to `query_row`:
    * For each glass `j` in row `i`:
        * Calculate `overflow = (mat[i][j] - 1.0) / 2.0`.
        * If `overflow > 0`:
            * Add `overflow` to `mat[i+1][j]`.
            * Add `overflow` to `mat[i+1][j+1]`.
4.  Return the value at `mat[query_row][query_glass]`, capped at **1.0**.

---

## ⏱ Complexity Analysis

* **Time Complexity**: $O(R^2)$ — Where $R$ is the number of rows (up to 100). we iterate through the triangular structure.
* **Space Complexity**: $O(R^2)$ — To store the 2D grid. (Note: This can be optimized to $O(R)$ using a 1D array).
* **Verdict**: ✅ **Optimal** for the given constraints.

---

## 📊 Example Trace

**Input**: `poured = 2, query_row = 1, query_glass = 1`

1.  **Row 0**: `mat[0][0]` starts with **2.0**.
    * `overflow = (2.0 - 1.0) / 2 = 0.5`.
    * `mat[1][0]` receives 0.5, `mat[1][1]` receives 0.5.
2.  **Row 1**: No further processing needed since we reached the `query_row`.
3.  **Result**: `mat[1][1]` is **0.5**.

**Final Result**: 0.5

---

## Final Notes

* **Memory Safety**: A $101 \times 101$ matrix of doubles uses approximately **81 KB**, well within the standard 256 MB limit of most platforms.
* **Precision**: Using `double` is necessary to handle the floating-point division as the champagne splits down the tower.

Happy coding 🚀
