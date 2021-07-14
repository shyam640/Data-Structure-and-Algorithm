// Question link -> https://leetcode.com/problems/longest-palindromic-substring/


class Solution {
public:
    string longestPalindrome(string s) {
        int i,left,right,len,max_len=1,n=s.length(),start=0;
        for (i=0;i<n;i++) {
            left=right=i;
            while (right<n-1 && s[right]==s[right+1]) {
                right++;
            }
            while (left>0 && right<n-1 && s[left-1]==s[right+1]) {
                left--;
                right++;
            }
            len=right-left+1;
            if (len>max_len) {
                max_len=len;
                start=left;
            }
        }
        return s.substr(start,max_len);
    }
};