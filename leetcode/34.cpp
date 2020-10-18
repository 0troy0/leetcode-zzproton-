#include<vector>
using namespace std;

class Solution {
public:
    int find_left(vector<int> nums, int target){
        int size=nums.size();
        int left=0, right=size-1;
        while(left<right){
            int mid=(left+right)>>1;
            if(nums[mid]<target) left=mid+1;
            else right=mid;
        }
        if(nums[left]!=target) return -1;
        return left;
    }
    int find_right(vector<int> nums, int target){
        int size=nums.size();
        int left=0, right=size-1;
        while(left<right){
            int mid=(left+right+1)>>1;
            if(nums[mid]>target) right=mid-1;
            else left=mid;
        }
        if(nums[left]!=target) return -1;
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int size=nums.size();
        vector<int> ans={-1, -1};
        if(size==0) return ans;
        int left=find_left(nums, target);
        if(left==-1) return ans;
        int right=find_right(nums, left);
        ans={left, right};
        return ans;
    }
};