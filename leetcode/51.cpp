#include<vector>
#include<string>
#include<cmath>
using namespace std;

//dfs
class Solution {
public:
    void dfs(vector<vector<string>>& res, vector<int>& pos, int row){
        int n=pos.size();
        if(row==n){
            vector<string> str(n, string(n, '.'));
            for(int i=0; i<n; ++i)
                str[i][pos[i]]='Q';
            res.push_back(str);
            return;
        }
        for(int col=0; col<n; ++col){
            if(isValid(pos, row, col)){
                pos[row]=col;
                dfs(res, pos, row+1);
                pos[row]=-1;
            }
        }
    }
    bool isValid(vector<int>& pos, int row, int col){
        for(int i=0; i<row; ++i)
            if(col==pos[i]||abs(row-i)==abs(col-pos[i])) return false;
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos(n, -1);
        dfs(res, pos, 0);
        return res;
    }
};

//位运算的dfs
class Solution {
private:
    int upperlim;
    vector<vector<string>> res;
public:
    void update(vector<string>& temp, int row, int p, char val){
        int col=0;
        while(!(p&1)){//不能用!(p|0)因为0可以写成n个0造成不只在第一位上运算
            p>>=1;
            col++;
        }
        temp[row][col]=val;
    }
    void dfs(vector<string>& temp, int below, int left, int right, int row){
        if(below==upperlim){
            res.push_back(temp);
            return;
        }
        
        int pos=upperlim&~(below|left|right);
        while(pos){
            int p=pos&(~pos+1);
            pos=pos-p;
            update(temp, row, p, 'Q');
            dfs(temp, below|p, (left|p)<<1, (right|p)>>1, row+1);
            update(temp, row, p, '.');
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        upperlim=(1<<n)-1;
        vector<string> temp(n, string(n, '.'));
        dfs(temp, 0, 0, 0, 0);
        return res;
    }
};