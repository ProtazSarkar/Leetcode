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
    bool is_possible(vector<int>& nums,int k,int t){
        int n=nums.size();
        //is this possible to get the target(t) in any subarray 
        //if any sum >t return false -> this is not the leargest sum
        // if the leargest sum > t and the i-j + 1 >= n-k return true
        
        int sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            while(sum > t){
                if(n-(i-j+1) <= (k-1)){
                    return false;
                }
                sum-=nums[j];
                j++;
            }
        }

        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        //spliting the array into k sub array
        //get the maxinum subarray sum fo those subarrays
        //i have a number(t) is this can be a leargest sum of any k subarrays
        //so subarray sum <= t  
        int n=nums.size();
        int left=0;int right=n-1;

        while(right - left > n-k){
            while(nums[left] > nums[right]) right--;
            while(nums[left] < nums[right]) left++;
        }

        int sum=0;
        for(int i=left;i<=right;i++){
            sum+=nums[i];
        }

        int max_sum=sum;
        for(int i=0;i<n;i++){
            if(i >= left && i<=right)   continue;
            max_sum=max(max_sum,nums[i]);
        }

        int l=0;int h=max_sum;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(is_possible(nums,k,mid)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }

        return ans;

    }
};