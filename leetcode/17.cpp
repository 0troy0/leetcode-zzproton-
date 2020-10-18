#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dic={"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if(digits.empty()) return res;
        res.push_back("");
        for(int i=0; i<digits.length(); ++i){
            string chars=dic[digits[i]-'0'];
            vector<string> temp;
            for(int j=0; j<chars.length(); ++j)
                for(int k=0; k<res.size(); ++k)
                    temp.push_back(res[k]+chars[j]);
            res=temp;
        }
        return res;
    }
};