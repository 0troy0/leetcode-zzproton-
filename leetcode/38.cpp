#include<string>
using namespace std;
//递归
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        if(n>30) return "error!";
        string s=countAndSay(n-1);
        string ans;
        int l=s.length();
        int i=1, count=1;
        while(i<l){
            if(s[i]!=s[i-1]){
                ans.push_back('0'+count);
                ans.push_back(s[i-1]);
                count=1;
            }
            else count++;
            if(i==l-1){
                ans.push_back('0'+count);
                ans.push_back(s[i]);
            }

            i++;
        }
        return ans;
    }
};
//迭代
class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=1; i<n; ++i){
            string temp;
            for(int j=0; j<s.length(); ++j){
                int count=1;
                while(j+1<s.length()&&s[j]==s[j+1]){
                    count++;
                    j++;
                }
                temp+=to_string(count)+s[j];
            }
            s=temp;
        }
        return s;
    }
};