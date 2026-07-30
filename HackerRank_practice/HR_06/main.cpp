#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void extraLongFactorials(int n) {
    vector<int> res;
    res.push_back(1); // 1! = 1
    
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (size_t j = 0; j < res.size(); j++) {
            long long prod = res[j] * i + carry;
            res[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    
    // Print in reverse order because least significant digits are stored first
    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        cout << *it;
    }
    cout << "\n";
}