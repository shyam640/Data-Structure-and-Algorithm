// Question Link --> https://leetcode.com/problems/letter-combinations-of-a-phone-number/



class Solution {
public:
    vector<string> keypadCode = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void DigitToString(string digits,string s){
        if(digits.length()==0){
            if(s.length()!=0)
             ans.push_back(s);
            return;
        }
        char ch = digits[0];
        string res = digits.substr(1);
        string code = keypadCode[ch-'0'-2];
        for(int i=0;i<code.length();i++)
            DigitToString(res,s+code[i]);
        return;
    }
    vector<string> letterCombinations(string digits) {
        string s = "";
        DigitToString(digits,s);
        return ans;
    }
};