#include<string>
#include<vector>
using namespace std;


#1
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1) return s;

        int start=0, max=1;
        vector<vector<int>> dp(len, vector<int>(len));

        for(int i=0; i<len; ++i){
            dp[i][i]=1;
            if(i<len-1 && s[i]==s[i+1]){
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }

        for(int d=3; d<=len; ++d)
            for(int i=0; i+d-1<len; ++i){
                int j=i+d-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    max=d;
                    dp[i][j]=1;
                    start=i;
                }
            }
        return s.substr(start, max);
    }
};

#2
class Solution {
public:
    string longestPalindrome(string s) {
        int left, right, maxleft=0, maxlen=1;

        if(s.size()<2) return s;

        int i=0;
        while(i<s.size()-maxlen/2){
            left=right=i;
            while(s[right]==s[right+1] && right<s.size()-1) right++;

            i=right+1;

            while(left>0 && right<s.size()-1 && s[left-1]==s[right+1]){
                left--;
                right++;
            }

            if(right-left+1>maxlen){
                maxlen=right-left+1;
                maxleft=left;
            }
        }
        return s.substr(maxleft, maxlen);
    }
};
