class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        sorted(cost,reverse=True)
        length=len(cost)
        i=0
        ans=0
        while i<length:
            ans+=cost[i]
            if i+1<length :
                ans+=cost[i+1]
            i+=3
        return ans
    

    