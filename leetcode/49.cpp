#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for(int i=0; i<strs.size(); ++i){
            string str=strs[i];
            sort(str.begin(), str.end());
            map[str].push_back(strs[i]);
        }
        for(auto i:map)
            res.push_back(i.second);
        return res;
    }
};