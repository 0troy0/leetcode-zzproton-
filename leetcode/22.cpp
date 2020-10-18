#include<string>
#include<vector>
using namespace std;

//递归
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if(n==0) return res;
        else func(n, "(", 1, 0);
        return res;
    }
    void func(int n, string str, int left, int right){
        if(left==n&&right==n){
            res.push_back(str);
            return;
        }
        if(left!=n) func(n, str+"(", left+1, right);
        if(left>right) func(n, str+=")", left, right+1);
    }
};

//dp
class Solution{
public:
    vector<string> generateParenthesis(int n){
        if(n==0) return{};
        if(n==1) return{"()"};

        vector<vector<string>> dp(n+1);
        dp[0]={""};
        dp[1]={"()"};
        for(int i=2; i<=n; ++i)
            for(int j=0; j<i; ++j)
                for(string p:dp[j])
                    for(string q:dp[i-1-j]){
                        string str="("+p+")"+q;
                        dp[i].push_back(str);
                    }

        return dp[n];
    }
};