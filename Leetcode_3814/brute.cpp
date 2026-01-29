class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        int maxCap = 0;

        // pick 1 item
        for (int i = 0; i < n; i++) {
            if (costs[i] < budget) maxCap = max(maxCap, capacity[i]);
        }

        // pick 2 items
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int totalCost = costs[i] + costs[j];
                if (totalCost < budget) {
                    maxCap = max(maxCap, capacity[i] + capacity[j]);
                }
            }
        }

        return maxCap;
    }
};