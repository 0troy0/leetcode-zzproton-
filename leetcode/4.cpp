#include<iostream>
#include<vector>
using namespace std;

#define max(a, b) ((a>b)?a:b)
#define min(a, b) ((a<b)?a:b)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        if(m>n) return findMedianSortedArrays(nums2, nums1);

        int L1, L2, R1, R2, lo=0, hi=2*m;

        while(lo<=hi){
            int C1=(lo+hi)/2;
            int C2=m+n-C1;

            L1=(C1==0)?INT32_MIN:nums1[(C1-1)/2];
            R1=(C1==2*m)?INT32_MAX:nums1[C1/2];
            L2=(C2==0)?INT32_MIN:nums2[(C2-1)/2];
            R2=(C2==2*n)?INT32_MAX:nums2[C2/2];

            if(L1>R2) hi=C1-1;
            else if(L2>R1) lo=C1+1;
            else break;
        }
        return (max(L1, L2)+min(R1, R2))/2.0;
    }
};