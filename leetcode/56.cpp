#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return intervals;
        sort(intervals.begin(), intervals.end());
        int left=intervals[0][0], right=intervals[0][1];
        vector<vector<int>> res;

        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i][0]<=right) right=right>intervals[i][1]?right:intervals[i][1];
            else{
                res.push_back({left, right});
                left=intervals[i][0];
                right=intervals[i][1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};