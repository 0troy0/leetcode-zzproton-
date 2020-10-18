#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size=nums.size();
        if(size==0||nums[0]>target) return 0;

        int left=0, right=size-1;
        while(left<right){
            int mid=(left+right)>>1;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return left;
    }
};