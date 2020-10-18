#include<vector>
using namespace std;

class Solution {
public:
    void DFS(vector<int>& candidates, int start, int target, vector<vector<int>>& res, vector<int>& path){
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i=start; i<candidates.size()&&target-candidates[i]>=0; ++i){
            path.push_back(candidates[i]);
            DFS(candidates, i, target-candidates[i], res, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        DFS(candidates, 0, target, res, path);
        return res;
    }
};