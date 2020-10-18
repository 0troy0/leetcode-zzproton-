#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;

        sort(nums.begin(), nums.end());
        
        for(int a=0; a<nums.size()-3; ++a){

            if(a>0&&nums[a]==nums[a-1]) continue;
            if(nums[a]+nums[a+1]+nums[a+2]+nums[a+3]>target) break;
            if(nums[a]+nums[nums.size()-3]+nums[nums.size()-2]+nums[nums.size()-1]<target) continue;

            for(int b=a+1; b<nums.size()-2; ++b){

                if(b>a+1&&nums[b]==nums[b-1]) continue;
                if(nums[a]+nums[b]+nums[a+1]+nums[a+2]>target) break;
                if(nums[a]+nums[b]+nums[nums.size()-2]+nums[nums.size()-1]<target) continue;

                int c=b+1, d=nums.size()-1;
                while(c<d){
                    int sum=nums[a]+nums[b]+nums[c]+nums[d];
                    if(sum==target)
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                    if(sum<=target){
                        c++;
                        while(nums[c]==nums[c-1]&&c<d) c++;
                    }
                    if(sum>=target){
                        d--;
                        while(nums[d]==nums[d+1]&&c<d) d--;
                    }
                }
            }
        }
        return res;
    }
};