#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int n=nums.size();
        int i=1;
        while(i<nums.size()){
            if(nums[i]==nums[i-1]){
                nums.erase(nums.begin()+i);
                n--;
            }
            else i++;
        }
        return n;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i=1;
        for(int j=1; j<nums.size(); ++j)
            if(nums[i-1]!=nums[j]) nums[i++]=nums[j];
        return i;
    }
};