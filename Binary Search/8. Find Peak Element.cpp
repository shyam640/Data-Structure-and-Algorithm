// Question Link --> https://leetcode.com/problems/find-peak-element/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Method 1 :- Using traversing O(n) solution
        // int ans=0;
        // int val=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     if(val<nums[i]){
        //         ans=i;
        //         val=nums[i];
        //     }
        // }
        // return ans;
        
        // Method 2 :- Using Binary Search
        int low=0,high=nums.size()-1;
        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[mid+1])
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};