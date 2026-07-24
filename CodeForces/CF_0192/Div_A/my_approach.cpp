#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Returns true if a repeating bigram can be formed, false otherwise
bool solve(vector<long long>& arr) {
    int count_ge_2 = 0;
    
    for (long long num : arr) {
        if (num >= 3) {
            return true; // Any single letter >= 3 is an immediate YES
        }
        if (num >= 2) {
            count_ge_2++;
        }
    }
    
    // Check if we found at least two different elements >= 2
    return (count_ge_2 >= 2);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; // Read number of test cases
    
    while (t--) {
        int k;
        cin >> k; // Read size of the array
        
        vector<long long> arr(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        
        // Pass the array to your solve function and print the result
        if (solve(arr)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}