#include<vector>
#include<algorithm>

//dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        int maximum=nums[0];
        vector<int> dp(size);
        dp[0]=nums[0];
        for(int i=1; i<size; ++i){
            dp[i]=max(dp[i-1]+nums[i], nums[i]);
            maximum=max(maximum, dp[i]);
        }
        return maximum;
    }
};

//更简洁
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum=nums[0];
        int p=nums[0];
        for(int i=1; i<nums.size(); ++i){
            p= max(p+nums[i], nums[i]);
            maximum=max(maximum, p);
        }
        return maximum;
    }
};

//分治
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return devideandconquer(nums, 0, nums.size()-1);
    }
    int devideandconquer(vector<int>& nums, int left, int right){
        if(left==right) return nums[left];
        if(left>right) return INT32_MIN;
        int mid=(left+right)/2;
        int l=devideandconquer(nums, left, mid-1);
        int r=devideandconquer(nums, mid+1, right);

        int k=nums[mid];
        int num_max=nums[mid];
        for(int i=mid-1; i>=left; --i){
            k+=nums[i];
            num_max=max(num_max, k)
        }

        k=num_max;
        
        for(int i=mid+1; i<=right; ++i){
            k+=nums[i];
            num_max=max(num_max, k);
        }

        return max(max(l, r), num_max);
    }
};