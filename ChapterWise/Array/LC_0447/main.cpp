#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;

        int n = points.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> freq;

            for(int j=0;j<n;j++){
                if(i == j)  continue;

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];

                int dis = dx * dx + dy * dy;

                freq[dis] ++;
            }

            for(auto [key,val] : freq){
                ans += val * (val-1);
            }
        }

        return ans;
    }
};