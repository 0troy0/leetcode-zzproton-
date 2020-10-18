#include<string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool first_match=!s.empty()&&(s[0]==p[0]||p[0]=='.');
        if(p.length()>=2&&p[1]=='*') return (first_match&&isMatch(s.substr(1), p))||isMatch(s, p.substr(2));
        else return first_match&&isMatch(s.substr(1), p.substr(1));
    }
};

//dp
class Solution{
public:
    bool isMatch(string s, string p){
        if(p.empty()) return s.empty();
        if(!p.empty()&&p[0]=='*') return false;
        int len1=s.length();
        int len2=p.length();
        vector<vector<bool>> dp(len1+1, vector<bool> (len2+1, false));
        dp[0][0]=true;

        for(int i=1; i<=len2; ++i)
            if(p[i-1]=='*') dp[0][i]=dp[0][i-1]||dp[0][i-2];
        
        for(int i=1; i<=len1; ++i)
            for(int j=1; j<=len2; ++j){
                if(s[i-1]==p[j-1]||p[j-1]=='.') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    if(p[j-2]==s[i-1]||p[j-2]=='.') dp[i][j]=dp[i-1][j]||dp[i][j-1]||dp[i][j-2];
                    else dp[i][j]=dp[i][j-2];
                }
            }
        return dp[len1][len2];
    }
};//faster a lot;