# 1382. Balance a Binary Search Tree

![LeetCode Difficulty Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Category Tree](https://img.shields.io/badge/Category-Tree-blue)

## 📝 Problem Description

Given the `root` of a binary search tree (BST), return a **balanced** binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is **balanced** if the depth of the two subtrees of every node never differs by more than **1**.



---

## 💡 Solution Strategy

The core challenge is converting a potentially "skewed" tree (where nodes lean heavily to one side) into a structure where heights are minimized.

### 1. Extract Sorted Data
By performing an **Inorder Traversal** (`Left -> Root -> Right`), we can extract all values from the BST into a dynamic array (vector). Because of the nature of BSTs, this array will automatically be sorted in ascending order.

### 2. Recursive Construction
Using the sorted array, we can build a height-balanced tree by repeatedly picking the **median** element as the current root. This ensures that the number of nodes is distributed as evenly as possible between the left and right subtrees.
* **Root:** The middle element of the current array segment.
* **Left Child:** The result of the same logic applied to the left half of the array.
* **Right Child:** The result of the same logic applied to the right half of the array.



---

## 📊 Complexity Analysis

| Complexity | Notation | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N)$ | We traverse each node once to create the array and visit each value once to rebuild the tree. |
| **Space Complexity** | $O(N)$ | We use an auxiliary vector to store all $N$ node values and $O(N)$ space for the recursion stack. |

---

## 🛠️ Implementation Notes
* **Midpoint Calculation:** We use `mid = start + (end - start) / 2` to prevent potential integer overflow.
* **Memory Management:** The solution creates a new tree structure. In a production environment, you might consider reusing existing `TreeNode` objects to save memory.

---

