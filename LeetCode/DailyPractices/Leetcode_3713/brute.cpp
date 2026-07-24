class Solution {
    bool is_balanced(string s, int l, int h){
        unordered_map<char, int> map;
        for(int i = l; i <= h; i++){
            // Simplified: if key doesn't exist, [] creates it with value 0, then increments
            map[s[i]]++; 
        }

        // Get the frequency of the first element in our map
        int static_freq = map.begin()->second; 
        
        for(auto const& [character, count] : map){
            if(count != static_freq){
                return false;
            }
        }
        return true;
    }

public:
    int longestBalanced(string s) {
        int n = s.length();
        if (n == 0) return 0; // Guard clause for empty strings
        
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(is_balanced(s, i, j)){
                    // Only update if the new length is actually greater
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
