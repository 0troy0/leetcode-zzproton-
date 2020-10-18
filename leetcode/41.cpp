#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=0;
        for(int i=0; i<nums.size(); ++i)
            if(nums[i]>0) n++;
        
        vector<bool> judge(n+1);
        for(int i=0; i<nums.size(); ++i)
            if(nums[i]<n+1&&nums[i]>0) judge[nums[i]]=true;
        
        for(int i=1; i<n+1; ++i)
            if(!judge[i]) return i;
        
        return n+1;
    }
};