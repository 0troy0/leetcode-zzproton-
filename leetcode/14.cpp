#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        else{
            int min=strs[0].size();
            string prefix="";
            for(int i=1; i<strs.size(); ++i)
                if(strs[i].size()<min) min=strs[i].size();
            for(int i=0; i<min; ++i){
                for(int j=1; j<strs.size(); ++j)
                    if(strs[j][i]!=strs[0][i]) return prefix;
                prefix.push_back(strs[0][i]);
            }
            return prefix;
        }
    }
};