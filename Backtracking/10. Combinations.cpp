// Question Link -> https://leetcode.com/problems/combinations/


class Solution {
public:
    vector<vector<int>> ans;
    void backtrackSolution(int n,int k,int idx,vector<int> temp){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i=idx+1;i<=n;i++){
            temp.push_back(i);
            backtrackSolution(n,k,i,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrackSolution(n,k,0,temp);
        return ans;
    }
};