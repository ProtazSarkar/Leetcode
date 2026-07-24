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

bool solve(vector<int> nums){
    int n=nums.size();
    int count_1=0;
    int count_2=0;
    int count_3=0;
    int part=1;
    for(int num : nums){
        if(num == 1)    count_1++;
        if(num == 2)    count_2++;
        if(num == 3)    count_3++;

        if(part == 1 && count_1>=count_2 && count_1>=count_3){
            part++;
            count_1=0;count_2=0;count_3=0;
        }
        if(part == 2 && count_1 >= count_3 && count_2 >= count_3){
            part++;
            count_1=0;count_2=0;count_3=0;
        }

        if(part == 3){
            part ++;
        }
    }

    return part >=4;

}