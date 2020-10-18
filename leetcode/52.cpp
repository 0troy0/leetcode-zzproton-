#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    int upperlim;
    int res=0;
public:
    int totalNQueens(int n) {
        upperlim=(1<<n)-1;
        dfs(0, 0, 0, 0);
        return res;
    }
    void dfs(int below, int left, int right, int row){
        if(below==upperlim){
            res++;
            return;
        }
        
        int pos=upperlim&~(below|left|right);
        while(pos){
            int p=pos&(~pos+1);
            pos=pos-p;
            dfs(below|p, (left|p)<<1, (right|p)>>1, row+1);
        }
    }
};