#include<vector>
#define min(a, b) (a<b)?a:b
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        if(size==0||size==1) return;

        int i=size-2;    
        while(i>=0&&nums[i]>=nums[i+1]) i--;

        if(i<0){
            reverse(nums.begin(), nums.end());
            return;
        }

        int j=size-1;
        while(j>i&&nums[j]<=nums[i]) j--;
        int temp=nums[j];
        nums[j]=nums[i];
        nums[i]=temp;

        reverse(nums.begin()+i+1, nums.end());

        return;
    }
};