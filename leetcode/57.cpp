#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {newInterval};

        vector<vector<int>> res;

        int index=0;
        while(index<intervals.size()&&newInterval[0]>intervals[index][0]) index++;//&&前后不能互换 好坑啊
        intervals.insert(intervals.begin()+index, newInterval);
        
        int left=intervals[0][0], right=intervals[0][1];
        for(int i=0; i<intervals.size(); ++i){
            if(right>=intervals[i][0]) right=right>intervals[i][1]?right:intervals[i][1];
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