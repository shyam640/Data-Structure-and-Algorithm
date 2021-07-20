// Question Link --> https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for(int i=0;i<prices.size()-1;i++){
            int flag=0;
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]<=prices[i]){
                    ans.push_back(prices[i]-prices[j]);
                    flag=1;
                    break;
                }
            }
            if(!flag)
                ans.push_back(prices[i]);
        }
        ans.push_back(prices[prices.size()-1]);
        return ans;
    }
};