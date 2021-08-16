// Question Link :- https://leetcode.com/problems/minimum-window-substring/


class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        // If length of s less then t else if length of any string is zero then return
        if(s.length()<t.length() or s.length()==0 or t.length()==0)
            return ans;
        
        // 
        int left=0,min_left=-1,count=0,minLen=s.length()+1;
        vector<int> letterCount(128,0);
        
        // Count frequency of each character of string t
        for(auto ch : t)
            letterCount[ch]++;
        
        // Move from left to right
        for(int i=0;i<s.length();i++){
            // Keeping track if all characters of t are included in substring
            if(--letterCount[s[i]]>=0)
                ++count;   // count=1 .... count=2 .... count=3
            
            while(count == t.size()){
                // if length of substing is less then minLen then update min length
                if(minLen > i-left+1){
                    minLen = i-left+1;
                    min_left = left;        // updating minLeft to left
                }
                // Increasing frequency of each character of 
                if(++letterCount[s[left]] > 0)
                    count--;
                ++left;
            }
        }
        return (min_left == -1) ? "" : s.substr(min_left , minLen);
    }
};