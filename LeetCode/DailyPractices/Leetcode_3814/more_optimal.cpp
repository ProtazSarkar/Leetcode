class Solution {
    struct cmp{
        bool operator()(const pair<int,int>& a,
                        const pair<int,int>& b) const {
            if(a.first == b.first){
                return a.second > b.second; // capacity descending for same cost
            }
            return a.first < b.first;     // cost ascending
        }
    };

    // Recursive binary search
    int bs(vector<pair<int,int>>& arr, int l, int h, int t){
        if(l > h) return h;  // last index with cost <= t if exact not found
        int mid = l + (h - l) / 2;
        if(arr[mid].first == t) return mid;
        if(arr[mid].first > t) return bs(arr, l, mid - 1, t);
        return bs(arr, mid + 1, h, t);
    }

public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> p(n);

        for(int i = 0; i < n; i++){
            p[i] = {costs[i], capacity[i]};
        }

        sort(p.begin(), p.end(), cmp());

        vector<int> preMax(n);
        preMax[0] = p[0].second;
        for(int i = 1; i < n; i++){
            preMax[i] = max(preMax[i-1], p[i].second);
        }

        int ans = 0;

        // Case: only one machine
        int idx = bs(p, 0, n - 1, budget - 1); // strictly less than budget
        if(idx >= 0){
            ans = preMax[idx];
        }

        // Case: two machines
        for(int i = 0; i < n; i++){
            if(p[i].first >= budget) break;

            int remain = budget - p[i].first;
            idx = bs(p, 0, i - 1, remain - 1); // strictly less than remaining budget

            if(idx >= 0){
                if(idx == i){
                    if(i > 0) idx = i - 1;
                    else continue;
                }
                ans = max(ans, p[i].second + preMax[idx]);
            }
        }

        return ans;
    }
};