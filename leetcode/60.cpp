#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int factorial(int n){
        if(n==0) return 1;
        return n*factorial(n-1);
    }

    string getPermutation(int n, int k) {
        string res="";
        vector<int> nums;
        for(int i=1; i<=n; ++i)
            nums.push_back(i);
        
        for(int j=0; j<n; ++j){
            int len=nums.size();
            int Mul=factorial(len-1);
            for(int i=1; i<=len; ++i)
                if((i-1)*Mul<k&&k<=i*Mul){
                    char c='0'+nums[i-1];
                    res+=c;
                    nums.erase(nums.begin()+i-1);
                    k-=Mul*(i-1);
                    break;
                }
        }
        return res;
    }
};