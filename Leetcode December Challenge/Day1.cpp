// Question Link - https://leetcode.com/problems/house-robber/


class Solution {
public:
    int rob(vector<int>& nums) {
        // Method 1 : Simple Iteration
        long long int even=0,odd=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                even += nums[i];
                even = (even>odd)?even:odd;
            }
            else{
                odd += nums[i];
                odd = (odd>even)?odd:even;
            }
        }
        return max(even,odd);
    }
};