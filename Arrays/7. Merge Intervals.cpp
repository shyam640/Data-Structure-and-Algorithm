// Question Link -- https://leetcode.com/problems/merge-intervals/


class Solution {
public:
    vector<vector<int>> removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto points : intervals) {
            if(ans.size()==0 or ans.back()[1]<points[0])
                ans.push_back(points);
            else{
                ans.back()[1] = max(ans.back()[1],points[1]);
            }
        }
        return ans;
    }
};