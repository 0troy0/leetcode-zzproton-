#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;

        sort(nums.begin(), nums.end());
        int left, mid, right, sum;
        for(left=0; left<nums.size()-2; ++left){
            if(nums[left]>0) break;
            if(left>0&&nums[left]==nums[left-1]) continue;
            mid=left+1;
            right=nums.size()-1;
            while(mid<right){
                sum=nums[mid]+nums[right];
                if(sum==-nums[left])
                    res.push_back({nums[left], nums[mid], nums[right]});
                if(sum<=-nums[left]){
                    mid++;
                    while(mid<right&&nums[mid]==nums[mid-1]) mid++;
                }
                if(sum>=-nums[left]){
                    right--;
                    while(mid<right&&nums[right]==nums[right+1]) right--;
                }
            }
        }
        return res;
    }
};