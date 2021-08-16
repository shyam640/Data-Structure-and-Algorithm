// Question Link --> https://leetcode.com/problems/combination-sum/



class Solution {
public:
    vector<vector<int>> ans;
    void getCombinations(vector<int>& candidates,int st,int sum,vector<int> subAns , int& target){
        if(sum==target){
            ans.push_back(subAns);
            return;
        }
        if(sum>target or st>candidates.size()-1)
            return;
        subAns.push_back(candidates[st]);
        getCombinations(candidates,st,sum+candidates[st],subAns,target);
        subAns.pop_back();
        getCombinations(candidates,st+1,sum,subAns,target);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        getCombinations(candidates,0,0,temp,target);
        return ans;
    }
};