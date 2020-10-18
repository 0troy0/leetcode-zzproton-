#include<cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0) return 1;
        double ans=1;
        long long m=(n>0)?n:-n;

        while(m){
            if(m&1) ans*=x;
            x*=x;
            m>>=1;
        }
        return (n>0)?ans:1/ans;
    }
};