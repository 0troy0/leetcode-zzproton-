#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.length();
        if(len==0) return 0;
        int i=len-1;
        while(i>=0&&s[i]==' ') i--;
        if(i==-1) return 0;
        int j=0;
        while(i>=0&&s[i]!=' '){
            i--;
            j++;
        }
        return j;
    }
};