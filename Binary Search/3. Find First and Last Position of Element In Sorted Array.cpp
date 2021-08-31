// Question Link --> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st = 0 , end = nums.size()-1;
        int stIdx,endIdx;
        vector<int> ans(2,-1);
        while(st<=end){
            if(nums[st]==target){
                ans[0] = st;
                break;
            }
            st++;
        }
        st = 0 ;
        end = nums.size()-1;
        while(end>=st){
            if(nums[end]==target){
                ans[1] = end;
                break;
            }
            end--;
        }
        return ans;
    }
};