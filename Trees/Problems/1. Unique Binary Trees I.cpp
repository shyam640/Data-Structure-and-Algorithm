// Question Link -> https://leetcode.com/problems/unique-binary-search-trees/


class Solution {
public:
    int numTrees(int n) {
        long long int ans = 1;
        for(int i=0;i<n;i++)
            ans *= ((4*i+2) / (i+2.));
        return ans;
    }
};