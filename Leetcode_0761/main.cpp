class Solution {
    
    string solve(string &s, int l, int h) {
        if (h - l <= 2) 
            return s.substr(l, h - l);

        // prefix balance array
        vector<int> counts(h - l + 1, 0);
        
        for (int i = l; i < h; i++) {
            if (s[i] == '1')
                counts[i - l + 1] = counts[i - l] + 1;
            else
                counts[i - l + 1] = counts[i - l] - 1;
        }

        vector<string> blocks;

        int i = 0, j = 1;

        while (j <= h - l) {
            if (counts[j] == 0) {
                // recursive call on inner part
                string inner = solve(s, l + i + 1, l + j - 1);
                
                string block = "1" + inner + "0";
                blocks.push_back(block);

                i = j;
            }
            j++;
        }

        // sort in descending order
        sort(blocks.begin(), blocks.end(), greater<string>());

        string ans = "";
        for (auto &b : blocks)
            ans += b;

        return ans;
    }

public:
    string makeLargestSpecial(string s) {
        return solve(s, 0, s.size());
    }
};