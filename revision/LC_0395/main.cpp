class Solution {
public:
    int longestSubstring(string s, int k) {
        int n =s.length();

        //base case
        if(n == 0 || n<k)   return 0;
        if(k == 1)  return n ;

        //create a freq map
        vector<int> freq(26,0);
        for(char c : s){
            int idx = c-'a';
            freq[idx] ++;
        }

        // search the first character that violet the condition
        int i =0;
        while(i<n && freq[s[i]-'a'] >= k){
            i++;
        }
        if(i == n)  return n;

        int left = longestSubstring(s.substr(0,i),k);

        while(i<n && freq[s[i]-'a'] < k){
            i++;
        }

        int right = longestSubstring(s.substr(i),k);

        return max(left,right);
    }
};