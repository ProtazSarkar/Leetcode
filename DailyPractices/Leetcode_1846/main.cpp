class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0]=1;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            int pre=arr[i-1];
            int expected=pre+1;
            if(expected<=arr[i]){
                arr[i]=expected;
                ans=expected;
            }else{
                ans=pre;
            }
        }
        return ans;
    }
};