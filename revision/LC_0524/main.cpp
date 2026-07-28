class Solution {
    bool is_subseq(string a ,string b){
        //a is the main string and b is the subsequesnt
        int j=0;
        for(int i=0;i<a.length();i++){
            if(j<b.length() && a[i] == b[j]){
                j++;
            }
        }
        return j == b.length();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(string d : dictionary){
            if(is_subseq(s,d)){
                if(ans.length() == d.length()){
                    if(ans > d){
                        ans = d;
                    }
                }else if(ans.length() < d.length()){
                    ans = d;
                }
            }
        }

        return ans;
    }
};