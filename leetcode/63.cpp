#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        for(int i=0; i<m; ++i){
            if(obstacleGrid[i][0]==1) break;
            dp[i][0]=1;
        }
        for(int i=0; i<n; ++i){
            if(obstacleGrid[0][i]==1) break;
            dp[0][i]=1;
        }

        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
                dp[i][j]=(obstacleGrid[i][j]==1)?0:dp[i-1][j]+dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};