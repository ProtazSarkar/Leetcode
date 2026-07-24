#include <bits/stdc++.h>
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

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {
    int n = a.size();
    
    // FIX 1: Max-heap for lower half, Min-heap for upper half
    priority_queue<int> lowers; 
    priority_queue<int, vector<int>, greater<int>> uppers;

    vector<double> ans;
    ans.reserve(n);
    
    for(int num : a){
        // Insert into the correct heap
        if(lowers.empty() || num <= lowers.top()){
            lowers.push(num);
        } else {
            uppers.push(num);
        }
        
        // FIX 2: Correct the rebalancing logic condition checks
        if (lowers.size() > uppers.size() + 1) {
            uppers.push(lowers.top());
            lowers.pop();
        } else if (uppers.size() > lowers.size()) { 
            // Keep lowers as the naturally larger one when odd
            lowers.push(uppers.top());
            uppers.pop();
        }

        // Calculate median
        if (lowers.size() == uppers.size()) {
            // FIX 3: Divide by 2.0 to preserve the decimal place
            ans.push_back((lowers.top() + uppers.top()) / 2.0);
        } else {
            // lowers will always hold the extra element if total size is odd
            ans.push_back((double)lowers.top());
        }
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
