## Problem: Minimum Cost for $k$-Capable Machine Learning Models

### Problem Statement
Given $n$ machine learning models, each with an associated cost and feature compatibility:
* $\text{cost}[i]$ represents the cost of the $i^{\text{th}}$ model.
* $\text{featureAvailability}[i]$ is a binary string indicating suitability for two distinct features:
  * `"00"`: not equipped for either feature
  * `"01"`: suitable for feature A but not feature B
  * `"10"`: suitable for feature B but not feature A
  * `"11"`: suitable for both features

A set of models is $k$-capable if the number of models suitable for feature A and the number suitable for feature B are both greater than or equal to $k$.

For each value of $k$ from $1$ to $n$, determine the minimum cost required to assemble a $k$-capable set of models. Return an array of $n$ integers, where the $i^{\text{th}}$ integer represents the minimum cost for an $i$-capable set. If no $i$-capable set exists, the $i^{\text{th}}$ integer should be `-1`.

---

### Solution Approach
The efficient way is to categorize the models into three groups:
- `onlyA`: strings like `01`
- `onlyB`: strings like `10`
- `both`: strings like `11`

For any fixed $k$, an optimal set can be formed by choosing some number of models from `both`, then filling the remaining needs for feature A and feature B from the cheapest `onlyA` and `onlyB` models.

So for each possible count $x$ of `both` models used:

$$
\text{cost}(x) = \text{prefixBoth}[x] + \text{prefixA}[k-x] + \text{prefixB}[k-x]
$$

We sort each category by cost and maintain prefix sums so that each candidate can be evaluated in constant time. The minimum valid value across all $x$ gives the answer for that $k$.

This reduces the complexity to roughly $O(n^2)$ overall because each $k$ scans only the sorted cost groups and uses prefix sums for fast lookups.

---

### Example
* $n = 6$
* $\text{cost} = [3, 6, 9, 1, 2, 5]$
* $\text{featureAvailability} = ["10", "01", "11", "01", "11", "10"]$

For $k \ge 5$, there will be no capable set. Hence, the answer is $[2, 6, 15, 26, -1, -1]$.

---

### Function Description
Complete the function `getMinimumCost` with the following parameters:
* `int cost[n]`: the cost of machine learning models
* `string featureAvailability[n]`: the compatibility string of models indicating their suitability for two features

#### Returns
* `int[n]`: the $i^{\text{th}}$ integer is the minimum cost of a $k$-capable set.
