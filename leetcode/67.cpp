#include<cstring>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aindex=a.length();
        int bindex=b.length();
        int ansindex=(aindex>bindex?aindex:bindex)+1;
        string ans(ansindex, '0');

        while(--ansindex>=0){
            int anum=--aindex>=0?a[aindex]-'0':0;
            int bnum=--bindex>=0?b[bindex]-'0':0;
            int carry=ans[ansindex]-'0';
            ans[ansindex]=(anum^bnum^carry)+'0';
            if(ansindex) ans[ansindex-1]=(anum&bnum|bnum&carry|carry&anum)+'0';
        }
        
        return ans[0]=='0'?ans.substr(1):ans;
    }
};