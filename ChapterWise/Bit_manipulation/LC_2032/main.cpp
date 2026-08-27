#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> mask(101,0);
        for(int x : nums1)  mask[x]|=1;
        for(int x : nums2)  mask[x]|=2;
        for(int x : nums3)  mask[x]|=4;

        vector<int>  result;
        for(int i=1;i<=100;i++){
            if(mask[i] == 3 || mask[i]== 5 || mask[i]== 6 || mask[i]== 7){
                result.push_back(i);
            }
        }
        return result;
    }
};