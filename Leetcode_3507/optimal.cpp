#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(nums.begin(), nums.end());

        // store indices where array is decreasing
        set<int> bad;
        for (int i = 0; i + 1 < n; i++) {
            if (arr[i] > arr[i + 1])
                bad.insert(i);
        }

        // min-heap storing {sum, index}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<>
        > pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({arr[i] + arr[i + 1], i});
        }

        int count = 0;

        while (!bad.empty()) {
            long long sum;
            int idx;

            // find a valid pair
            while (true) {
                auto top = pq.top();
                pq.pop();
                sum = top.first;
                idx = top.second;

                if (idx + 1 < arr.size() &&
                    arr[idx] + arr[idx + 1] == sum)
                    break; // valid
            }

            count++;

            // remove affected bad indices
            bad.erase(idx - 1);
            bad.erase(idx);
            bad.erase(idx + 1);

            // merge
            arr[idx] = sum;
            arr.erase(arr.begin() + idx + 1);

            // recheck local order
            if (idx - 1 >= 0 && arr[idx - 1] > arr[idx])
                bad.insert(idx - 1);
            if (idx + 1 < arr.size() && arr[idx] > arr[idx + 1])
                bad.insert(idx);

            // push new adjacent sums
            if (idx - 1 >= 0)
                pq.push({arr[idx - 1] + arr[idx], idx - 1});
            if (idx + 1 < arr.size())
                pq.push({arr[idx] + arr[idx + 1], idx});
        }

        return count;
    }
};

int main() {
    return 0;
}