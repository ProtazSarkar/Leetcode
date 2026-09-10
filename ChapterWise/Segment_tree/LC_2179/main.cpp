#include <iostream>
#include <sstream>

// Containers
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>

// Associative Containers (Trees/Hashes)
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

// Algorithms & Utilities
#include <algorithm>
#include <numeric>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
    vector<int> tree;
    int size;

    int query(int node, int l, int r, int ql, int qr) {

        if (r < ql || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = l + (r - l) / 2;

        int left = query(2 * node + 1, l, mid, ql, qr);
        int right = query(2 * node + 2, mid + 1, r, ql, qr);

        return left + right;
    }

    void update(int node, int l, int r, int pos) {

        if (l == r) {
            tree[node]++;
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid) {
            update(2 * node + 1, l, mid, pos);
        }
        else {
            update(2 * node + 2, mid + 1, r, pos);
        }

        tree[node] =
            tree[2 * node + 1] +
            tree[2 * node + 2];
    }

    int query(int ql, int qr) {

        if (ql > qr)
            return 0;

        return query(0, 0, size - 1, ql, qr);
    }

    void update(int pos) {
        update(0, 0, size - 1, pos);
    }

public:

    long long goodTriplets(vector<int>& nums1,
                           vector<int>& nums2) {

        int n = nums1.size();

        size = n;
        tree.resize(4 * n, 0);

        // pos2[value] = position of value in nums2
        vector<int> pos2(n);

        for (int i = 0; i < n; i++) {
            pos2[nums2[i]] = i;
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {

            int y = nums1[i];

            // Position of nums1[i] in nums2
            int pos = pos2[y];

            // Previous elements whose position in nums2
            // is smaller than current position.
            int valid_ele_left = query(0, pos - 1);

            // Number of previous elements
            int total_left = i;

            // Previous elements whose position in nums2
            // is greater than current position.
            int invalid_ele_left =
                total_left - valid_ele_left;

            // Total elements after current position in nums2
            int total_right = n - 1 - pos;

            // Remove elements that are already used on the left
            // and have position greater than current position.
            int valid_ele_right =
                total_right - invalid_ele_left;

            total += (long long)valid_ele_left *
                     valid_ele_right;

            // Mark current position as processed
            update(pos);
        }

        return total;
    }
};