#include<vector>
#include<cstdlib>
#include<stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left={0};
        int h=0;
        int ans=0;
        for(int i=0; i<height.size(); ++i)
            if(height[i]>h){
                left.insert(left.end(), height[i]-h, i);
                h=height[i];
            }
        
        for(int i=0; i<height.size(); ++i)
            for(int j=1; j<=height[i]; ++j){
                ans+=i-left[j]-1;
                left[j]=i;
            }
        
        return ans+left.size()-1;
    }
};//数据大时很慢

class Solution{
public:
    int trap(vector<int>& height) {
        int size=height.size();
        if(size==0) return 0;
        int ans=0;
        vector<int> left_max(size), right_max(size);

        left_max[0]=height[0];
        for(int i=1; i<size; ++i)
            left_max[i]=max(left_max[i-1], height[i]);
        right_max[size-1]=height[size-1];
        for(int i=size-2; i>=0; --i)
            right_max[i]=max(right_max[i+1], height[i]);
        
        for(int i=1; i<size-1; ++i)
            ans+=min(left_max[i], right_max[i])-height[i];
        
        return ans;
    }
};

//stack
class Solution{
public:
    int trap(vector<int>& height) {
        int ans=0, current=0;
        stack<int> st;
        while(current<height.size()){
            while(!st.empty()&&height[current]>height[st.top()]){
                int top=st.top();
                st.pop();
                if(st.empty()) break;
                int distance=current-st.top()-1;
                int bounded_height=min(height[current], height[st.top()])-height[top];
                ans+=distance*bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};

//双指针
class Solution{
public:
    int trap(vector<int>& height) {
        int ans=0, left=0, right=height.size()-1;
        int left_max=0, right_max=0;
        while(left<right){
            if(height[left]<height[right]){
                height[left]>=left_max?(left_max=height[left]):ans+=left_max-height[left];
                left++;
            }
            else{
                height[right]>=right_max?(right_max=height[right]):ans+=right_max-height[right];
                right--;
            }
        }
        return ans;
    }
};