#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool is_sorted(vector<int>& arr){
        for(int i = 0; i + 1 < arr.size(); i++){
            if(arr[i] > arr[i+1]) return false;
        }
        return true;
    }

    pair<int,int> get_min_sum(vector<int>& arr){
        int idx = -1;
        int minsum = INT_MAX;
        for(int i = 0; i + 1 < arr.size(); i++){
            int sum = arr[i] + arr[i+1];
            if(sum < minsum){
                minsum = sum;
                idx = i;
            }
        }
        return {minsum, idx};
    }

    vector<int> remove_pair(vector<int>& arr){
        auto [sum, idx] = get_min_sum(arr);
        vector<int> temp;
        for(int i = 0; i < arr.size(); i++){
            if(i == idx){
                temp.push_back(sum);
                i++; // skip adjacent
            } else {
                temp.push_back(arr[i]);
            }
        }
        return temp;
    }

public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        vector<int> arr = nums;
        while(!is_sorted(arr)){
            arr = remove_pair(arr);
            count++;
        }
        return count;
    }
};