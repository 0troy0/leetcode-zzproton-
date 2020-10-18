#include<vector>
using namespace std;
//number overflow
class Solution {
public:
    long long factorial(int n){
        if(n==0) return 1;
        return long long(n*factorial(n-1));
    }
    int uniquePaths(int m, int n) {
        int d=m+n-2;
        int u=m<n?m-1:n-1;
        return int(factorial(d)/(factorial(u)*factorial(d-u)));
    }
};
//dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        return dp[m-1][n-1];
    }
};