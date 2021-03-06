#include<string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.length(), n2=num2.length();
        string ans(n1+n2, '0');
        for(int i=n2-1; i>=0; --i)
            for(int j=n1-1; j>=0; --j){
                int temp=ans[i+j+1]-'0'+(num1[j]-'0')*(num2[i]-'0');
                ans[i+j+1]=temp%10+'0';
                ans[i+j]+=temp/10;
            }
        for(int i=0; i<n1+n2; ++i)
            if(ans[i]!='0') return ans.substr(i);
        
        return "0";
    }
};