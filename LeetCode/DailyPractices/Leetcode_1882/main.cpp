#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // Min-heap for free servers: stores {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        
        // Min-heap for busy servers: stores {free_time, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> time_to_free;

        for (int i = 0; i < servers.size(); i++) {
            free_servers.push({servers[i], i});
        }

        int m = tasks.size();
        vector<int> ans(m, -1);
        long long time = 0;
        int j = 0;

        while (j < m) {
            // Free up servers that are ready by the current time
            while (!time_to_free.empty() && time_to_free.top().first <= time) {
                auto [t, s] = time_to_free.top();
                time_to_free.pop();
                free_servers.push({servers[s], s});
            }

            // If no servers are available, jump time to the next available server
            if (free_servers.empty()) {
                time = time_to_free.top().first;
                continue;
            }

            // Tasks arrive at second j, so time cannot be less than j
            time = max(time, (long long)j);

            // Re-check freeing up servers at the updated time
            while (!time_to_free.empty() && time_to_free.top().first <= time) {
                auto [t, s] = time_to_free.top();
                time_to_free.pop();
                free_servers.push({servers[s], s});
            }
            
            if (free_servers.empty()) {
                time = time_to_free.top().first;
                continue;
            }

            // Assign the task to the best available server
            auto [w, s] = free_servers.top();
            free_servers.pop();

            time_to_free.push({time + tasks[j], s});
            ans[j] = s;
            j++;
        }

        return ans;
    }
};