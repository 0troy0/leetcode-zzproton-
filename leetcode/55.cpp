#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximum=0;
        for(int i=0; i<nums.size(); ++i){
            maximum=max(maximum, i+nums[i]);
            if(maximum>=nums.size()-1) return true;
            if(nums[i]==0&&maximum<=i) return false;
        }
        return true;
    }
};