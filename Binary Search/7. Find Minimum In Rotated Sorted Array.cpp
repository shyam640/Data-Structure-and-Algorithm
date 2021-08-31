// Question Link --> https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/


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
    
    int findMin(vector<int>& nums) {
        // Method 1 :- Using STL
        return *min_element(nums.begin(),nums.end());
        // OR
        // sort(nums.begin(),nums.end());
        // return nums[0];
        
        // Method 2 :- Sorting array using rotation (Gives TLE)
        // rotateArrayUntilSorted(nums);
        // return nums[0];
    }
};