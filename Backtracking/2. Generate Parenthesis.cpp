// Question Link --> https://leetcode.com/problems/generate-parentheses/



class Solution {
public:
    void addParenthesisString(vector<string> &ans,int pos,int n,int open,int close){
        static char str[100];
        if(close==n){
            ans.push_back(str);
            return;
        }else{
            if(open>close){
                str[pos]=')';
                addParenthesisString(ans,pos+1,n,open,close+1);
            }
            if(open<n){
                str[pos]='(';
                addParenthesisString(ans,pos+1,n,open+1,close);
            }
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        addParenthesisString(ans,0,n,0,0);
        return ans;
    }
};