class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string repeting = word;

        while(sequence.find(repeting) != npos){
            ans++;
            repeting+=word;
        }
        return ans;
    }
};