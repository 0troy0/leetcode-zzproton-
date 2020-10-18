#include<vector>
#define max(a, b) a>b?a:b
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;

        int end=0;
        int maxPosition=0;
        int steps=0;
        for(int i=0; i<n-1; ++i){
            maxPosition=max(maxPosition, i+nums[i]);
            if(i==end){
                steps++;
                end=maxPosition;
            }
        }
        return steps;
    }
};