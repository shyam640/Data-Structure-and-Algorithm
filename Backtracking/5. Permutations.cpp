// Question Link --> https://leetcode.com/problems/permutations/



class Solution {
public:
    vector<vector<int>> ans;
    void getPermutations(vector<int>& nums,int pos){
        if(pos==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i=pos;i<nums.size();i++){
            swap(nums[i],nums[pos]);
            getPermutations(nums,pos+1);
            swap(nums[i],nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // Method 1 -> Using STL
        // vector<vector<int>> ans;
        // ans.push_back(nums);
        // while(1){
        //     next_permutation(nums.begin(),nums.end());
        //     if(count(ans.begin(),ans.end(),nums)>0)
        //         break;
        //     ans.push_back(nums);
        // }
        // return ans;
        
        // Method 2 -> Using Backtracking
        if(nums.size()==0 or nums.size()==1){
            ans.push_back(nums);
            return ans;
        }
        getPermutations(nums,0);
        return ans;
    }
};