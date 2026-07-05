#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int getNum(int p){
        if(p % 2 == 0){
            return -1;
        }

        int temp = p;
        int counter = 1;

        while(temp & 1){
            temp >>= 1;
            counter <<= 1;
        }

        counter >>= 1;
        return p ^ counter;
    }

public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, 0);

        for(int i = 0; i < size; i++){
            ans[i] = getNum(nums[i]);
        }
        return ans;
    }
};

int main(){
    return 0;
}
