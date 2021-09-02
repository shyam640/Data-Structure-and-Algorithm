// Question Link --> https://leetcode.com/problems/find-the-duplicate-number


class Solution {
public:
    int getDuplicate(vector<int>& nums,int cur){
        if(cur == nums[cur])
            return cur;
        int nxt = nums[cur];
        nums[cur] = cur;
        return getDuplicate(nums,nxt);
    }
    
    int findDuplicate(vector<int>& nums) {
        
        // Method 1 :- Binary Search                                        O(NlogN) Solution
        // Lambda Function to count all numbers less then or equal to cur
//         auto count_small_and_equal = [&](int cur){
//             int count=0;
//             for(auto &num:nums){
//                 if(num<=cur)
//                     count++;
//             }
//             return count;
//         };
        
//         int low=1,high=nums.size();
//         int duplicate=-1;
//         while(low<=high){
//             int cur = (low+high)/2;
//             if(count_small_and_equal(cur) > cur){
//                 duplicate = cur;
//                 high = cur-1;
//             }else
//                 low = cur+1;
//         }
//         return duplicate;
        
        
        // Method 2 :- Sort Array and traverse array with a check          O(NlogN) Solution
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i] == nums[i+1])
        //         return nums[i];
        // }
        // return -1;
        
        
        // Method 3 :- Using Array and Hashmap
        return getDuplicate(nums,0);
    }
};