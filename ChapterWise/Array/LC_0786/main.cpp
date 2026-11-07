#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0.0, right = 1.0;

        int num_idx = 0, den_idx = 0;

        for (int iter = 0; iter < 60; ++iter) {
            double mid = left + (right - left) / 2.0;

            int count = 0;
            double max_frac = 0.0;
            int j = 1;

            for (int i = 0; i < n; ++i) {
                while (j < n && arr[i] > mid * arr[j]) {
                    ++j;
                }

                count += (n - j);

                if (j < n) {
                    double frac = (double)arr[i] / arr[j];
                    if (frac > max_frac) {
                        max_frac = frac;
                        num_idx = i;
                        den_idx = j;
                    }
                }
            }

            if (count == k) {
                return {arr[num_idx], arr[den_idx]};
            } else if (count > k) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return {arr[num_idx], arr[den_idx]};
    }
};