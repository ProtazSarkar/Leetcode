import java.util.*;

class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int total_cost=0;
        for(int i=cost.length;i>=0;i--){
            total_cost+=cost[i];
            if(i-1>=0){
                //include the 2nd one
                total_cost+=cost[i-1];
            }
            //skip the 3rd one with whole chunk
            i-=2;
        }
    }
}