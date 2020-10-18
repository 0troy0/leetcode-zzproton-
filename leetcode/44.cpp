#include<string>
using namespace std;
//回溯
class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0, star=-1, k=0;
        while(i<s.length()){
            if(s[i]==p[j]||p[j]=='?'){
                i++;
                j++;
            }
            else if(p[j]=='*'){
                star=j++;
                k=i;
            }
            else if(star!=-1){
                i=++k;
                j=star+1;
            }
            else return false;
        }
        while(j<p.length()&&p[j]=='*') j++;
        return j==p.length();
    }
};
//dp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(), n=p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0]=true;
        for(int i=1; i<=n; ++i){
            if(p[i-1]=='*') dp[0][i]=true;
            else break;
        }

        for(int i=1; i<=m; ++i)
            for(int j=1; j<=n; ++j){
                if(p[j-1]=='?'||s[i-1]==p[j-1]) dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }

        return dp[m][n];
    }
};