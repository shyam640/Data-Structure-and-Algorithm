// Question Link --> https://leetcode.com/problems/longest-valid-parentheses/


class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(), open=0, close=0, ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else close++;
            if(open==close) ans=max(ans, open+close);
            if(close>open) close=open=0;
        }
        open=close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(open==close) ans=max(ans, open+close);
            if(close<open) close=open=0;
        }
        return ans;
            
    }
};