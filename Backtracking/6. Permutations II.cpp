// Question Link --> https://leetcode.com/problems/permutations-ii/



class Solution {
public:
    vector<vector<int>> ans;
    void getPermutations(vector<int>& nums , int pos){
        while(1){
            ans.push_back(nums);
            next_permutation(nums.begin(),nums.end());
            if(count(ans.begin(),ans.end(),nums))
                break;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        getPermutations(nums,0);
        return ans;
    }
};