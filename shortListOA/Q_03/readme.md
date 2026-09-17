# Dual GPU Idleness Minimizer

## Problem Description
A game renders shaders using two GPUs: `a` and `b`. The string `shader` represents which GPU is used for each shader, where:
* `shader[i] = 'a'` means GPU $a$ is used for the $i$-th shader.
* `shader[i] = 'b'` means GPU $b$ is used.

The **idleness** of this dual GPU system is defined as the maximum number of shaders for which the same GPU is used consecutively. 

To reduce idleness, you can perform the following operation at most `switchCount` times:
* Select any index $i$ and change `shader[i]` from `'a'` to `'b'` or vice versa.

### Goal
Find the **minimum possible idleness** that can be achieved by applying these operations optimally.

---

## Function Description
Complete the function `findMinimumIdleness` in the editor with the following parameters:
* `string shader`: the GPU used for each shader.
* `int switchCount`: the maximum number of operations allowed.

### Returns
* `int`: the minimum possible idleness achieved.

---

## Example
* **Input:** `shader = "aabbbaaaa"`, `switchCount = 2`
* **Output:** `2`
* **Explanation:** 
  1. Switch `shader[3]` to get `"aababaaaa"`
  2. Switch `shader[6]` to get `"aabababaa"`
  Now `shader = "aabababaa"`, and the system has a maximum consecutive run (idleness) of `2`.