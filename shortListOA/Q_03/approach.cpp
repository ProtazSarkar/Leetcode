#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function signature required by the problem
bool is_possible(int k,string shader,int switchCount){
    int count = 0;
    int n = shader.length();

    int i=0;
    while(i<n){
        int j = i;
        while(j<n && shader[i] == shader[j]){
            j++;
        }

        int blocklen = j-i;
        count += blocklen / (k+1);
    }
    return count <= switchCount;
}

int findMinimumIdleness(string shader, int switchCount) {
    int n = shader.length();

    int left = 1;
    int right = n;
    int ans = right;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(is_possible(mid,shader,switchCount)){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    
    return ans;
}

int main() {
    // Example Test Case
    string shader = "aabbbaaaa";
    int switchCount = 2;
    
    int result = findMinimumIdleness(shader, switchCount);
    cout << "Minimum Idleness: " << result << endl;
    
    return 0;
}