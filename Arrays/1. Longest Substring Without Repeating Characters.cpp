// Question link -> https://leetcode.com/problems/longest-substring-without-repeating-characters/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            map<char,int> mp;
            int len=0;
            for(int j=i;j<s.length();j++){
                if(mp[s[j]]>0){
                    break;
                }
                mp[s[j]]++;
                len++;
            }
            ans = max(ans,len);
        }
        return ans;
        
    }
};