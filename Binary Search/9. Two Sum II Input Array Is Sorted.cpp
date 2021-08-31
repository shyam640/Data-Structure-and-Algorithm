// Question Link --> https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Method 1 :- Traversing simple to whole vector O(n^2) Solution
        // vector<int> ans;
        // for(int i=0;i<numbers.size();i++){
        //     for(int j=i+1;j<numbers.size();j++){
        //         if(numbers[i]+numbers[j]==target){
        //             ans.push_back(i+1);
        //             ans.push_back(j+1);
        //             break;
        //         }
        //     }
        //     if(ans.size()>0)
        //         break;
        // }
        // return ans;
        
        // Method 2 :- Binary Search Solution Optimized O(N*logN) Solution
        vector<int> ans;
        for(int i=0;i<numbers.size()-1;i++){
            int low=i+1,high=numbers.size()-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(numbers[mid] == target-numbers[i]){
                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    return ans;
                }else if(numbers[mid] > target-numbers[i])
                    high = mid-1;
                else
                    low = mid+1;
            }
        }
        return ans;
        
        // Method 3 :- Two Pointer Method
        // vector<int> ans;
        // int ptr1=0,ptr2=numbers.size()-1;
        // while(ptr1<=ptr2){
        //     if(numbers[ptr1]+numbers[ptr2] == target){
        //         ans.push_back(ptr1+1);
        //         ans.push_back(ptr2+1);
        //         return ans;
        //     }else if(numbers[ptr1]+numbers[ptr2] > target)
        //         ptr2--;
        //     else
        //         ptr1++;
        // }
        // return ans;
    }
};