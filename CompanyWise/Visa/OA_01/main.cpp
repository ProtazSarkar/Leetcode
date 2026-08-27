#include <vector>
using namespace std;

class Solution {
public:
    int sumOfPeaks(std::vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for(int i=0;i<arr.size();i++){
            if((i-1<0 || arr[i-1] < arr[i]) && (i+1 ==n || arr[i+1] < arr[i])){
                sum += arr[i];
            }
        }
        return sum;
    }
};