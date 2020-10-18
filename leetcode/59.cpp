#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {{}};
        if(n==1) return {{1}};
        vector<vector<int>> res(n, vector<int>(n));

        int j=1;
        int left=0, right=n-1;
        int up=0, down=n-1;
        while(true){
            for(int i=left; i<=right; ++i) res[up][i]=j++;
            if(++up>down) break;
            for(int i=up; i<=down; ++i) res[i][right]=j++;
            if(--right<left) break;
            for(int i=right; i>=left; --i) res[down][i]=j++;
            if(--down<up) break;
            for(int i=down; i>=up; --i) res[i][left]=j++;
            if(++left>right) break;
        }
        return res;
    }
};