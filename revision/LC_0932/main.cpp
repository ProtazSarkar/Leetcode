class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n == 1){
            return {1};
        }

        vector<int> odds = beautifulArray((n+1)/2);
        vector<int> evens = beautifulArray(n/2);

        vector<int> ans ;
        for(int x : odds){
            ans.push_back(2*x -1);
        }
        for(int x : evens){
            ans.push_back(2*x);
        }
        return ans;
    }
};