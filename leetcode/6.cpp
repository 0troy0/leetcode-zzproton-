#include<string>
using namespace std;

#define min(a, b) ((a<b)?a:b)

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;

        int i=0, n=min(numRows, s.size());
        bool flag=false;
        vector<string> t(n);

        for(char c:s){
            t[i]+=c;
            if(i==0||i==n-1) flag=!flag;
            i+=(flag)?1:-1;
        }

        string res;
        for(string row:t) res+=row;
        return res;
    }
};