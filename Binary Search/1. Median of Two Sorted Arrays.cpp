// Question Link --> https://leetcode.com/problems/median-of-two-sorted-arrays/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Brute force approach 
        vector<int> helper;
        double ans;
        for(int i=0;i<nums1.size();i++)
            helper.push_back(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            helper.push_back(nums2[i]);
        sort(helper.begin(),helper.end());
        int size =nums1.size()+nums2.size();
        if(size%2==0){
            // type casting from int to double so we don't get integer answer
            ans = (((double)(helper[size/2-1])+(double)(helper[size/2]))/2);
            return ans;
        }else{
            ans = (double)(helper[size/2]);
            return ans;
        }
    }
};