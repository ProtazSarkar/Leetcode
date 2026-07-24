#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<pair<int,int>> landRides(landDuration.size());
        vector<pair<int,int>> waterRides(waterDuration.size());

        for(int i=0;i<landDuration.size();i++){
            landRides[i].first=landStartTime[i];
            landRides[i].second=landDuration[i];
        }

        for(int i=0;i<waterDuration.size();i++){
            waterRides[i].first=waterStartTime[i];
            waterRides[i].second=waterDuration[i];
        }

        sort(landRides.begin(),landRides.end());
        sort(waterRides.begin(),waterRides.end());

        // i have two option that i can choose the land ride first or water ride fast
        

    }
};