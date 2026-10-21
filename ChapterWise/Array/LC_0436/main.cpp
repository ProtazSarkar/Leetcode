#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int bs(int k, int l, int h, vector<pair<int, int>>& arr) {
        if (l > h) return -1; // Fixed 'r' to 'h' and return -1
        
        int mid = l + (h - l) / 2;

        if (arr[mid].first == k) {
            return arr[mid].second;
        }
        if (arr[mid].first < k) {
            return bs(k, mid + 1, h, arr);
        }
        
        // If arr[mid].first > k, it's a potential answer, 
        // but check if there's a valid index further left
        int left_ans = bs(k, l, mid - 1, arr);
        return (left_ans != -1) ? left_ans : arr[mid].second;
    }

public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts;

        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }

        sort(starts.begin(), starts.end());
        int max_ = starts[n - 1].first; // Fixed: access .first of the pair

        vector<int> ans;
        for (auto interval : intervals) {
            int end = interval[1];
            if (end > max_) {
                ans.push_back(-1);
            } else {
                ans.push_back(bs(end, 0, n - 1, starts));
            }
        }

        return ans;
    }
};