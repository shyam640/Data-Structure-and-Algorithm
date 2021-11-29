// Question Link -> https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left=0,right=0,n=s.length(),maxLen=0,lcost=0;
        while(right<n){
            lcost += abs((s[right]-'a') - (t[right]-'a'));
            while(lcost>maxCost){
                lcost -= abs((s[left]-'a') - (t[left]-'a'));
                left++;
            }
            maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};