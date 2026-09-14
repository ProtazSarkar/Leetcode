class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long left = 0;
        long long right = 1000;
        int cnt = 0;

        while(right <= n){
            ans+=(right-left)*cnt;
            cnt++;
            left = right;

            if(right > LONG_MAX/1000)  break;
            right *= 1000;
        }

        if(left <= n){
            ans+=(n-left+1)*cnt;
        }

        return ans;
    }
};