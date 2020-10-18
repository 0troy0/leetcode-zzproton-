#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void swap(int& a, int& b){
        int temp=a;
        a=b;
        b=temp;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int i){
        if(i==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int j=i; j<nums.size(); ++j){
            swap(nums[i], nums[j]);
            backtrack(nums, res, i+1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }
};

class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, unordered_map<int, int>& dic, int i){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int j=0; j<nums.size(); ++j){
            if(dic[j]!=0) continue;
            dic[j]=1;
            temp.push_back(nums[j]);
            dfs(nums, res, temp, dic, i+1);
            dic[j]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        unordered_map<int, int> dic;
        dfs(nums, res, temp, dic, 0);
        return res;
    }
};