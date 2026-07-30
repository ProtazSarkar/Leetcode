#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Distance to edges of the board
    int up = n - r_q;
    int down = r_q - 1;
    int right = n - c_q;
    int left = c_q - 1;
    
    int up_right = min(up, right);
    int up_left = min(up, left);
    int down_right = min(down, right);
    int down_left = min(down, left);
    
    for (const auto& obs : obstacles) {
        int r_obs = obs[0];
        int c_obs = obs[1];
        
        // Check if obstacle is in the same column
        if (c_obs == c_q) {
            if (r_obs > r_q) {
                up = min(up, r_obs - r_q - 1);
            } else if (r_obs < r_q) {
                down = min(down, r_q - r_obs - 1);
            }
        }
        // Check if obstacle is in the same row
        else if (r_obs == r_q) {
            if (c_obs > c_q) {
                right = min(right, c_obs - c_q - 1);
            } else if (c_obs < c_q) {
                left = min(left, c_q - c_obs - 1);
            }
        }
        // Check if obstacle is on a diagonal
        else if (abs(r_obs - r_q) == abs(c_obs - c_q)) {
            if (r_obs > r_q && c_obs > c_q) {
                up_right = min(up_right, r_obs - r_q - 1);
            } else if (r_obs > r_q && c_obs < c_q) {
                up_left = min(up_left, r_obs - r_q - 1);
            } else if (r_obs < r_q && c_obs > c_q) {
                down_right = min(down_right, r_q - r_obs - 1);
            } else if (r_obs < r_q && c_obs < c_q) {
                down_left = min(down_left, r_q - r_obs - 1);
            }
        }
    }
    
    return up + down + right + left + up_right + up_left + down_right + down_left;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
