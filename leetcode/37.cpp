#include<vector>
using namespace std;

class Solution {
public:
    bool row[9][9]={false}, col[9][9]={false}, block[9][9]={false};

    bool check(vector<vector<char>>& board, int i, int j, int num){
        int k=i/3*3+j/3;
        if(row[i][num]||col[j][num]||block[k][num]) return false;
        return true;
    }
    //函数定义的时候加引用&会快很多 可能是因为引用不用新开内存存储board
    bool solveonce(vector<vector<char>>& board, int i, int j){
        if(i==9) return true;
        if(board[i][j]!='.') return solveonce(board, i+(j+1)/9, (j+1)%9);
        int k=i/3*3+j/3;
        for(char c='1'; c<='9'; ++c){
            int num=c-'0'-1;
            if(check(board, i, j, num)){
                board[i][j]=c;
                row[i][num]=col[j][num]=block[k][num]=true;
                if(solveonce(board, i+(j+1)/9, (j+1)%9)) return true;
                board[i][j]='.';
                row[i][num]=col[j][num]=block[k][num]=false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i)
            for(int j=0; j<9; ++j)
                if(board[i][j]!='.'){
                    int k=i/3*3+j/3;
                    int num=board[i][j]-'0'-1;
                    row[i][num]=col[j][num]=block[k][num]=true;
                }
        solveonce(board, 0, 0);
    }
};