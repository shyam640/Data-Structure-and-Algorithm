// Question Link --> https://leetcode.com/problems/4sum/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int left=j+1,right=nums.size()-1;
                int target1 = target-nums[i]-nums[j];
                while(left<right){
                    int sum = nums[left]+nums[right];
                    if(sum<target1) left++;
                    else if(sum>target1) right--;
                    else{
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[left];
                        temp[3] = nums[right];
                        ans.push_back(temp);
                        while(left<right and nums[left]==temp[2]) left++;
                        while(left<right and nums[right]==temp[3]) right--;
                    }
                }
                while(j+1<nums.size() and nums[j+1]==nums[j]) j++;
            }
            while(i+1<nums.size() and nums[i+1]==nums[i]) i++;
        }
        return ans;
    }
};