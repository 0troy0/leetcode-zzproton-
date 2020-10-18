#include<string>
#include<vector>
#include<stack>
#define max(a, b) (a>b)?a:b
using namespace std;
//dp
class Solution {
public:
    int longestValidParentheses(string s) {
        int size=s.length();
        int ans=0;
        vector<int> dp(size, 0);
        for(int i=1; i<size; ++i){
            if(s[i]==')'){
                if(s[i-1]=='(') dp[i]=(i>=2?dp[i-2]:0)+2;
                else if(i-dp[i-1]>0&&s[i-dp[i-1]-1]=='(') dp[i]=dp[i-1]+(i-dp[i-1]>=2?dp[i-dp[i-1]-2]:0)+2;
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};
//stack
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        stack<int> n;
        n.push(-1);
        for(int i=0; i<s.length(); ++i){
            if(s[i]=='(') n.push(i);
            else{
                n.pop();
                if(n.empty()) n.push(i);
                else ans=max(ans, i-n.top());
            }
        }
        return ans;
    }
};
//两次遍历
class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0, right=0, ans=0;
        for(int i=0; i<s.length(); ++i){
            if(s[i]=='(') left++;
            else right++;
            if(left==right) ans=max(2*left, ans);
            else if(right>left) left=right=0;
        }
        left=right=0;
        for(int i=s.length()-1; i>=0; --i){
            if(s[i]=='(') left++;
            else right++;
            if(left==right) ans=max(2*left, ans);
            else if(left>right) left=right=0;
        }
        return ans;
    }
};