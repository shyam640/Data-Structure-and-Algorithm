// Question Link -> https://leetcode.com/problems/subsets


class Solution {
public:
    vector<vector<int>> ans;
    void backtrackSubsets(vector<int>& nums,vector<int>& temp,int k){
        if(k==nums.size()){
            ans.push_back(temp);
            return;
        }
        backtrackSubsets(nums,temp,k+1);
        temp.push_back(nums[k]);
        backtrackSubsets(nums,temp,k+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrackSubsets(nums,temp,0);
        return ans;
    }
};