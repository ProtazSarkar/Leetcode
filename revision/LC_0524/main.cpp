class Solution {
    bool is_subseq(string a, string b){
        // a is the main string and if b is the sunsequent
        int j=0;
        for(int i=0;i<a.length();i++){
            if(j<b.length() && b[j]==a[i]){
                j++;
            }
        }

        return j == b.length();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(string dic : dictionary){
            if(is_subseq(s,dic)){
                if(ans.length() == dic.length()){
                    if(ans > dic){
                        ans = dic;
                    }
                }else{
                    if(ans.length() < dic.length()){
                        ans = dic;
                    }
                }
            }
        }

        return ans;
    }
};