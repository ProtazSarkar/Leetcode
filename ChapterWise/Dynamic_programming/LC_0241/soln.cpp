#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

class Solution {
    unordered_map<string, vector<int>> memo;

public:
    vector<int> diffWaysToCompute(string expression) {
        // If already computed, return the cached result
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        vector<int> result;
        int n = expression.size();

        for (int i = 0; i < n; ++i) {
            char c = expression[i];
            
            // If the character is an operator, split the problem
            if (c == '+' || c == '-' || c == '*') {
                string left_expr = expression.substr(0, i);
                string right_expr = expression.substr(i + 1);

                vector<int> left_results = diffWaysToCompute(left_expr);
                vector<int> right_results = diffWaysToCompute(right_expr);

                // Combine all results from left and right sub-expressions
                for (int l : left_results) {
                    for (int r : right_results) {
                        if (c == '+') {
                            result.push_back(l + r);
                        } else if (c == '-') {
                            result.push_back(l - r);
                        } else if (c == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        // Base case: if the string is just a number (no operators found)
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return memo[expression] = result;
    }
};