//暴力法

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> ans(2);
        for(i=0;i<nums.size()-1;++i)
            for(j=i+1;j<nums.size();++j){
                if(nums[i]+nums[j]==target){
                    ans[0]=i;
                    ans[1]=j;
                    return ans;
                }
            }
        return ans;
    }   
};


//hash1
#include<map>

class solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> table;
        vector<int> res(2, -1);

        for(int i=0; i<nums.size(); ++i){
            if(table.count(target-nums[i])==1){
                res[0]=table[target-nums[i]];
                res[1]=i;
            }
            table[nums[i]]=i;
        }

        return res;
}
};