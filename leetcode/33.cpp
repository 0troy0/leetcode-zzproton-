#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return -1;
        int left=0, right=n-1;
        int rotation=0;
        if(nums[left]>nums[right])
            while(left<=right){
                int pivot=(left+right)/2;
                if(nums[pivot]>nums[pivot+1]){
                    rotation=pivot+1;
                    break;
                }
                else{
                    if(nums[pivot]<nums[left]) right=pivot-1;
                    else left=pivot+1;
                }
            }

        
        left=rotation;
        right=left+n-1;
        while(left<=right){
            int mid=(left+right)/2;
            int realmid=mid%n;
            if(nums[realmid]==target) return realmid;
            else if(nums[realmid]>target) right=mid-1;
            else left=mid+1;
        }

        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(nums[0]>target^nums[0]>nums[mid]^target>nums[mid]) left=mid+1;
            else right=mid;
        }
        return left==right&&nums[left]==target?left:-1;
    }
};