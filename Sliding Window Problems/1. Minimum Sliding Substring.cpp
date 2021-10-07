// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.


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