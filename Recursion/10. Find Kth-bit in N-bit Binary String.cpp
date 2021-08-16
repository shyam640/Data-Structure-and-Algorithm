// Question Link --> https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/



class Solution {
public:
    string invert(string rev){
        for(int i=0;i<rev.length();i++){
            if(rev[i]=='0')
                rev[i] = '1';
            else
                rev[i] = '0';
        }
        return rev;
    }
    string generate(int n){
        string ans = "0";
        for(int i=0;i<n;i++){
            string s = ans;
            reverse(s.begin(),s.end());
            string extra = invert(s);
            ans += "1" + extra;
        }
        return ans;
    }
    char findKthBit(int n, int k) {
        string s = generate(n);
        return s[k-1];
    }
};