class Solution {
    public int maxCapacity(int[] costs, int[] capacity, int budget) {
        int n = costs.length;
        int maxCapacity = 0;

        // Pick one item
        for (int i = 0; i < n; i++) {
            if (costs[i] < budget) {
                maxCapacity = Math.max(maxCapacity, capacity[i]);
            }
        }

        // Pick two items
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // j = i+1 to avoid same item
                int totalCost = costs[i] + costs[j];
                int totalCapacity = capacity[i] + capacity[j];
                if (totalCost < budget) {
                    maxCapacity = Math.max(maxCapacity, totalCapacity);
                }
            }
        }

        return maxCapacity;
    }
}