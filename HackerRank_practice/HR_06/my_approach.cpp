#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
 
string mul(string s , int d){
    string result = "";
    int n = s.length();
    
    int carry = 0;
    for(int i=n-1;i>=0;i--){
        int num = s[i] - '0';
        int r = (num * d)+carry;
        carry = r/10;
        r%=10;
        result.push_back(r+'0');
    }
    
    if(carry)   result.push_back(carry+'0');
    reverse(result.begin(),result.end());
    return result;
}

string add(string s1,string s2){
    int n= s1.length();
    int m = s2.length();
    
    int i=n-1;
    int j=m-1;
    
    string result = "";
    
    int carry = 0;
    while(i>=0 || j>=0){
        int a ;
        if(i<0){
            a=0;
        }else{
            a = s1[i]-'0';
        }
        
        int b ;
        if(j<0){
            b = 0;
        }else{
            b = s2[j]-'0';
        }
        
        int sum = a+b+carry;
        carry = sum/10;
        sum = sum % 10;
        
        result.push_back(sum + '0');
        i--;
        j--;
    }
    
    if(carry)   result.push_back(carry + '0');
    reverse(result.begin(),result.end());
    
    return result;
    
}

string multiply(string s , int i){
    int n = s.length();
    string result = "";
    string multiplicant = to_string(i);
    int m = multiplicant.length();
    
    int padding = 0;
    for(int j=m-1;j>=0;j--){
        string inter = mul(s,multiplicant[j]-'0');
        for(int k=0;k<padding;k++){
            inter.push_back('0');
        }
        padding++;
        result = add(result,inter);
    }
    return result;
}

void extraLongFactorials(int n) {
    string ans = "1";
    for(int i=1;i<=n;i++){
        ans = multiply(ans, i);
    }
    cout << ans;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
 
string mul(string s , int d){
    string result = "";
    int n = s.length();
    
    int carry = 0;
    for(int i=n-1;i>=0;i--){
        int num = s[i] - '0';
        int r = (num * d)+carry;
        carry = r/10;
        r%=10;
        result.push_back(r+'0');
    }
    
    if(carry)   result.push_back(carry+'0');
    reverse(result.begin(),result.end());
    return result;
}

string add(string s1,string s2){
    int n= s1.length();
    int m = s2.length();
    
    int i=n-1;
    int j=m-1;
    
    string result = "";
    
    int carry = 0;
    while(i>=0 || j>=0){
        int a ;
        if(i<0){
            a=0;
        }else{
            a = s1[i]-'0';
        }
        
        int b ;
        if(j<0){
            b = 0;
        }else{
            b = s2[j]-'0';
        }
        
        int sum = a+b+carry;
        carry = sum/10;
        sum = sum % 10;
        
        result.push_back(sum + '0');
        i--;
        j--;
    }
    
    if(carry)   result.push_back(carry + '0');
    reverse(result.begin(),result.end());
    
    return result;
    
}

string multiply(string s , int i){
    int n = s.length();
    string result = "";
    string multiplicant = to_string(i);
    int m = multiplicant.length();
    
    int padding = 0;
    for(int j=m-1;j>=0;j--){
        string inter = mul(s,multiplicant[j]-'0');
        for(int k=0;k<padding;k++){
            inter.push_back('0');
        }
        padding++;
        result = add(result,inter);
    }
    return result;
}

void extraLongFactorials(int n) {
    string ans = "1";
    for(int i=1;i<=n;i++){
        ans = multiply(ans, i);
    }
    cout << ans;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
