#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i=0, res=0, sign=1;

        while(i<str.size()&&str[i]==' ') ++i;
        if(i==str.size()) return 0;
        if(str[i]=='-'){
            sign=-1;
            ++i;
        }
        else if(str[i]=='+') ++i;
        while(i<str.size()&&isdigit(str[i])){
            if(sign==1&&(res>INT32_MAX/10||(res==INT32_MAX/10&&str[i]-'0'>=7))) return INT32_MAX;
            if(sign==-1&&(-1*res<INT32_MIN/10||(-1*res==INT32_MIN/10&&str[i]-'0'>=8))) return INT32_MIN;
            res=res*10+(str[i++]-'0');
        }
        return res*sign;
    }
};