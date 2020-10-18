using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long longdividend=labs(dividend), longdivisor=labs(divisor), n=0;
        int sign=(dividend>0)^(divisor>0)?-1:1;

        while(longdividend>=longdivisor){
            longdividend-=longdivisor;
            n++;
        }
        n=sign*n;
        if(n<INT32_MIN||n>INT32_MAX) return INT32_MAX;
        return n;
    }
};//time exceeded

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        long long longdividend=labs(dividend), longdivisor=labs(divisor), n=0, cur_bit=1;
        int sign=(dividend>0)^(divisor>0)?-1:1;

        while(longdividend>=longdivisor<<1){
            longdivisor<<=1;
            cur_bit<<=1;
        }

        while(cur_bit>0){
            if(longdividend>=longdivisor){
                longdividend-=longdivisor;
                n+=cur_bit;
            }
            cur_bit>>=1;
            longdivisor>>=1;
        }
        n=sign*n;
        if(n<INT32_MIN||n>INT32_MAX) return INT32_MAX;
        return n;
    }
};