// Question Link --> https://leetcode.com/problems/search-in-rotated-sorted-array-ii/


class Solution {
public:
    // void rotateArrayUntilSorted(vector<int>& nums){
    //     while(1){
    //         int last = nums[nums.size()-1];
    //         if(last>nums[0])
    //             break;
    //         for(int i=nums.size()-2;i>=0;i--)
    //             nums[i+1] = nums[i];
    //         nums[0] = last;
    //     }
    // }
    
    bool search(vector<int>& nums, int target) {
        // Method 1 :- Using STL
        // sort(nums.begin(),nums.end());
        // if(binary_search(nums.begin(),nums.end(),target))
        //     return true;
        // return false;
        
        // Method 2 :- Using a bit of STL
        sort(nums.begin(),nums.end());
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
        
        // Method 3 :- Rotating the Array and Binary Search (But will result into TLE)
        // rotateArrayUntilSorted(nums);
        // int low=0,high=nums.size()-1;
        // while(low<=high){
        //     int mid = low+(high-low)/2;
        //     if(nums[mid]==target)
        //         return true;
        //     else if(nums[mid]>target)
        //         high = mid-1;
        //     else
        //         low = mid+1;
        // }
        // return false;
    }
};