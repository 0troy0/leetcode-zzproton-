#include<string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry=0;
        for(int i=num1.length()-1, j=num2.length()-1; i>=0||j>=0; --i, --j){
            int sum=carry;
            sum+=(i>=0)?num1[i]-'0':0;
            sum+=(j>=0)?num2[j]-'0':0;
            ans.insert(ans.begin(), '0'+sum%10);
            carry=sum/10;
        }
        if(carry==1) ans.insert(ans.begin(), '1');

        return ans;
    }
};