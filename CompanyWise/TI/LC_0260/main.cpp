#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_sum = 0;
        for(int num : nums){
            xor_sum ^= num;
        }
        int pos = 1;
        for(int i=0;i<31;i++){
            if(pos & xor_sum){
                break;
            }
            pos <<= 1;
        }
        int a = 0;
        int b = 0;
        for(int num : nums){
            if(num & pos){
                a^=num;
            }else{
                b^=num;
            }
        }
        return {a,b};
    }
};