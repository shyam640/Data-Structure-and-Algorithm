// Question Link --> https://leetcode.com/problems/regular-expression-matching/


class Solution {
public:
    bool isMatch(string s, string p) {
        // Method 1 -> Recursion
        if(p.length()==0) return s.length()==0;
        bool firstMatch = (!(s.length()==0) and (p[0] == s[0] or p[0] == '.'));
        if(p.length()>=2 and p[1]=='*'){
            return (isMatch(s,p.substr(2)) or (firstMatch and isMatch(s.substr(1),p)));
        }else{
            return firstMatch and isMatch(s.substr(1) , p.substr(1));
        }
    }
};