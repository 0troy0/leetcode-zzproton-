#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, vector<int> used, int index){
        if(index==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); ++i){
            if(used[i]) continue;
            if(i>0&&nums[i-1]==nums[i]&&used[i-1]) continue;
            used[i]=1;
            temp.push_back(nums[i]);
            dfs(nums, res, temp, used, index+1);
            used[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> used(nums.size(), 0);
        dfs(nums, res, temp, used, 0);
        return res;
    }
};