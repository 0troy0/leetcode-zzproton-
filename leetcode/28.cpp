#include<string>
#include<vector>
using namespace std;

#define max(a, b) ((a>b)?a:b)

//暴力法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
        int m=haystack.length();
        int n=needle.length();
        for(int i=0; i<m-n+1; ++i){
            int j=0;
            while(j<n&&haystack[i+j]==needle[j]){
                if(j==n-1) return i;
                j++;
            }
        }
        return -1;
    }
};

//KMP
class Solution {
public:
    vector<int> getnext(string str){
        int len=str.length();
        vector<int> next;
        next.push_back(-1);
        int i=0, j=-1;
        while(i<len-1){
            if(j==-1||str[i]==str[j]){
                i++;
                j++;
                if(str[i]!=str[j])
                    next.push_back(j);
                else next.push_back(next[j]);
            }
            else j=next[j];
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
        int i=0, j=0, len1=haystack.length(), len2=needle.length();
        vector<int> next=getnext(needle);
        while(i<len1&&j<len2){
            if(j==-1||haystack[i]==needle[j]){
                i++;
                j++;
            }
            else j=next[j];
        }
        if(j==len2) return i-j;
        return -1;
    }
};

//Sunday
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int i=0, j=0, k, m=needle.length();
        while(i<haystack.length()){
            if(haystack[i]!=needle[j]){
                for(k=needle.length()-1; k>=0; --k)
                    if(needle[k]==haystack[m]) break;
                i=m-k;
                j=0;
                m=i+needle.length();
                if(m>haystack.length()) return -1;
            }
            else{
                if(j==needle.length()-1) return i-j;
                i++;
                j++;
            }
        }
        return -1;
    }
};

//BM
class Solution {
public:
    void get_bmB(string T, vector<int>& bmB){
        int t=T.length();
        for(int i=0; i<256; ++i)
            bmB.push_back(t);
        for(int i=0; i<t-1; ++i)
            bmB[T[i]]=t-i-1;
    }
    void get_suffix(string T, vector<int>& suff){
        int t=T.length();

        for(int i=t-2; i>=0; --i){
            int k=i;
            while(k>=0&&T[k]==T[t-1-i+k]) k--;
            suff[i]=i-k;
        }
    }
    void get_bmG(string T, vector<int>& bmG){
        int t=T.length();
        vector<int> suff(t, 0);
        get_suffix(T, suff);
        for(int i=0; i<t; ++i)
            bmG[i]=t;

        for(int i=t-1; i>=0; --i)
            if(suff[i]==i+1)
                for(int j=0; j<t-1-i; ++j)
                    if(bmG[j]==t)
                        bmG[j]=t-1-i;
        
        for(int i=0; i<t-1; ++i)
            bmG[t-1-suff[i]]=t-1-i;
    }
    int strStr(string haystack, string needle){
        int i=0, h=haystack.length(), n=needle.length();
        vector<int> bmB;
        vector<int> bmG(n, 0);
        get_bmB(needle, bmB);
        get_bmG(needle, bmG);

        while(i<=h-n){
            int j=n-1;
            while(j>-1&&haystack[i+j]==needle[j]) j--;
            if(j==-1) return i;
            i+=max(bmG[j], bmB[haystack[i+j]]-(n-1-j));
        }
        return -1;
    }
};