// Question Link --> https://leetcode.com/explore/featured/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3960/


class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=INT_MAX){
                int start = nums[i],count=0;
                while(nums[start]!=INT_MAX){
                    int temp=start;
                    start = nums[start];
                    count++;
                    nums[temp] = INT_MAX;
                }
                ans = max(ans,count);
            }
            
        }
        return ans;
    }
};