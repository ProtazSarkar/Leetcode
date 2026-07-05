class Solution {
    bool is_possible(vector<int>& gas, vector<int>& cost, int i){
        int n = gas.size();
        int tank = gas[i] - cost[i];

        if(tank < 0) return false;

        int j = (i+1) % n;

        while(j != i){
            tank += gas[j] - cost[j];
            if(tank < 0) return false;
            j = (j+1) % n;
        }

        return true;
    }

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); i++){
            if(is_possible(gas, cost, i)){
                return i;
            }
        }
        return -1;
    }
};