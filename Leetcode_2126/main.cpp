#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int currMass=mass;

        for (int astro : asteroids){
            if(currMass<astro){
                return false;
            }
            else{
                currMass+=astro;
            }
        }
        return true;
    }
};