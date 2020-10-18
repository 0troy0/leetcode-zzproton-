#include<cstring>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int pnum=0, xnum=0, nnum=0;
        int i;
        bool headflag=true, spaceflag=false;
        int pt;
        for(i=0; i<s.length(); ++i){
            if(headflag){
                if((s[i]>='0'&&s[i]<='9')||s[i]=='+'||s[i]=='-'||s[i]=='.'){
                    headflag=false;
                    pt=i;
                    if(s[i]>='0'&&s[i]<='9') nnum++;
                    if(s[i]=='.') pnum++;
                    continue;
                }
                else if(s[i]==' ') continue;
                else return false;
            }

            if(s[i]==' '){
                spaceflag=true;
                continue;
            }

            if(!spaceflag&&s[i]>='0'&&s[i]<='9'){
                nnum++;
                pt++;
                continue;
            }

            if(!spaceflag&&s[i]=='.'){
                if(pnum>0||xnum>0) return false;
                pnum++;
                pt++;
                continue;
            }

            if(!spaceflag&&s[i]=='e'){
                if(xnum>0||nnum==0) return false;
                xnum++;
                pt++;
                continue;
            }

            if(!spaceflag&&(s[i]=='+'||s[i]=='-')){
                if(s[i-1]=='e'){
                    pt++;
                    continue;
                }
                else return false;
            }

            else return false;
        }

        if(((s[pt]>='0'&&s[pt]<='9')||s[pt]=='.')&&nnum!=0) return true;
        else return false;
    }
};

//暴力法我吐了