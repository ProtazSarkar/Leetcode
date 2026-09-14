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

    void buildTree(int node,int l,int r,vector<int>& nums){
        if(l==r){
            tree[node] = l;return ;
        }

        int left_node = 2*node + 1;
        int right_node = 2*node +2;

        int mid = l + (r-l)/2;
        buildTree(left_node,l,mid,nums);
        buildTree(right_node,mid+1,r,nums);

        if(nums[tree[left_node]] < nums[tree[right_node]]){
            tree[node] = tree[left_node];
        }else{
            tree[node] = tree[right_node];
        }
    }

    int query(int node,int ql,int qr,int l,int r,vector<int>& nums){
        if(ql>r || qr<l)    return -1;
        if(ql<=l && qr>=r){
            return tree[node];
        }

        int left_node = 2*node +1;
        int right_node = 2*node + 2;

        int mid = l + (r-l)/2;

        int left = query(left_node,ql,qr,l,mid,nums);
        int right = query(right_node,ql,qr,mid+1,r,nums );

        if(left == -1)  return right;
        if(right == -1) return left;

        return (nums[left] < nums[right]) ? left : right;

    }

    int MOD = 1e9 + 7;
    int solve(int l,int r,vector<int>& nums){
        if(l>r) return 0;

        int min_idx = query(0,l,r,0,nums.size()-1,nums);

        long long  left_ele = min_idx - l + 1;
        long long right_ele = r - min_idx + 1;

        long long total = ((left_ele * right_ele) % MOD)*nums[min_idx] % MOD;

        int left_part = solve(l,min_idx-1,nums);
        int right_part = solve(min_idx+1,r,nums);

        return (total + left_part + right_part)%MOD;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        tree.resize(4*n,0);
        buildTree(0,0,n-1,arr);
        return solve(0,n-1,arr);
    }
};