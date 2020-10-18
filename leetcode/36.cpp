#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={false}, col[9][9]={false}, box[9][9]={false};
        for(int i=0; i<9; ++i)
            for(int j=0; j<9; ++j)
                if(board[i][j]!='.'){
                    int k=i/3*3+j/3;
                    int num=board[i][j]-'0'-1;
                    if(row[i][num]||col[j][num]||box[k][num]) return false;
                    else row[i][num]=col[j][num]=box[k][num]=true;
                }
        return true;
    }
};