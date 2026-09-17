#include <iostream>
#include <vector>
#include <string>
#include <algorithum>

using namespace std;

class Solution {
public:
    vector<int> getMinimumCost(vector<int>& cost, vector<string>& featureAvailability) {
        int n = cost.size();
        vector<int> result(n, -1);
        
        // TODO: Implement your logic here
        // Hint: Categorize models based on their feature availability 
        // ("00", "01", "10", "11") and compute the minimum cost for each k from 1 to n.

        vector<pair<int,int>> modelA;
        vector<pair<int,int>> modelB;

        for(int i=0;i<n;i++){
            if(featureAvailability[i][0] == '1'){
                modelA.push_back({cost[i],i});
            }
            if(featureAvailability[i][1] == '1'){
                modelB.push_back({cost[i],i});
            }
            if(featureAvailability[0][0] == '1' && featureAvailability[0][1] == '1'){
                is_both[i] = true;
            }
        }

        sort(modelA.begin(),modelB.end());
        sort(modelB.begin(),modelB.end());

        vector<bool> is_picked(n,false);
        int end = min(modelA.size(),modelB.size());

        for(int i=0;i<end;i++){
            int total_cost = 0;
            if(i-1>=0){
                total_cost = result[i-1];
            }

            auto [costA,idA] = modelA[i];
            if(!is_picked[idA]){
                total_cost += costA;
                is_picked[idA] = true;
            }

            auto [costB,idB] = modelB[i];
            if(!is_picked[idB]){
                total_cost += costB;
                is_picked[idB] = true;
            }

            result[i] = total_cost;
        }
        
        for(int i=end;i<n;i++){
            result[i] = -1;
        }
        
        return result;
    }
};

// Example Test Case
int main() {
    Solution sol;
    int n = 6;
    vector<int> cost = {3, 6, 9, 1, 2, 5};
    vector<string> featureAvailability = {"10", "01", "11", "01", "11", "10"};
    
    vector<int> ans = sol.getMinimumCost(cost, featureAvailability);
    
    cout << "Result: [";
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i + 1 == ans.size() ? "" : ", ");
    }
    cout << "]" << endl;
    
    return 0;
}