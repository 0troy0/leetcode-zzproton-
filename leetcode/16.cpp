#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min=INT32_MAX, res;
        sort(nums.begin(), nums.end());
        for(int left=0; left<nums.size()-2; ++left){
            if(left>0&&nums[left]==nums[left-1]) continue;
            int mid=left+1, right=nums.size()-1;
            while(mid<right){
                int sum=nums[left]+nums[mid]+nums[right];
                if(sum==target) return sum;
                if(abs(target-sum)<min){
                    res=sum;
                    min=abs(target-sum);
                }
                if(sum<target){
                    mid++;
                    while(nums[mid]==nums[mid-1]&&mid<right) mid++;
                }
                else{
                    right--;
                    while(nums[right]==nums[right+1]&&mid<right) right--;
                }
            }
        }
        return res;
    }
};