#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Cmp {
        bool operator()(const pair<long long, list<long long>::iterator>& a,
                        const pair<long long, list<long long>::iterator>& b) const {
            if (a.first != b.first)
                return a.first < b.first;
            // tie-break using address (safe, does NOT compare iterators)
            return &(*a.second) < &(*b.second);
        }
    };

public:
    int minimumPairRemoval(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        list<long long> arr(nums.begin(), nums.end());

        // {pairSum, iterator to left element}
        set<pair<long long, list<long long>::iterator>, Cmp> pq;

        auto add_pair = [&](list<long long>::iterator it) {
            auto nx = next(it);
            if (nx != arr.end()) {
                pq.insert({*it + *nx, it});
            }
        };

        // initialize all adjacent pairs
        for (auto it = arr.begin(); next(it) != arr.end(); ++it) {
            add_pair(it);
        }

        int count = 0;

        while (true) {
            // check if non-decreasing
            bool ok = true;
            auto it = arr.begin();
            auto prv = it;
            ++it;

            for (; it != arr.end(); ++it) {
                if (*it < *prv) {
                    ok = false;
                    break;
                }
                prv = it;
            }
            if (ok) break;

            // get minimum sum adjacent pair
            auto cur = *pq.begin();
            pq.erase(pq.begin());

            auto left = cur.second;
            auto right = next(left);

            // erase affected old pairs
            if (left != arr.begin()) {
                auto lprev = std::prev(left);
                pq.erase({*lprev + *left, lprev});
            }
            pq.erase({*left + *right, left});
            if (next(right) != arr.end()) {
                pq.erase({*right + *next(right), right});
            }

            // merge
            *left += *right;
            arr.erase(right);

            // insert updated pairs
            if (left != arr.begin()) {
                add_pair(std::prev(left));
            }
            add_pair(left);

            count++;
        }

        return count;
    }
};