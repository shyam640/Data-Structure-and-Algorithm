// Question Link -> https://leetcode.com/problems/subsets
// Question Link -> https://leetcode.com/problems/subsets-ii/


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



class Solution {
public:
    vector<vector<int>> ans;
    void backtrackSolution(vector<int>& nums,vector<int> temp,int idx){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }
        backtrackSolution(nums,temp,idx+1);
        temp.push_back(nums[idx]);
        backtrackSolution(nums,temp,idx+1);
        temp.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        backtrackSolution(nums,temp,0);
        for(int i=0;i<ans.size();i++)
            sort(ans[i].begin(),ans[i].end());
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};