// Question Link --> https://leetcode.com/problems/permutation-sequence/


class Solution {
public:
    string getPermutation(int n, int k) {
        // Method 1 --> Using stl
        int num=0;
        for(int i=1;i<=n;i++){
            num = num*10 + i;
        }
        string s = to_string(num);
        for(int i=0;i<k-1;i++){
            next_permutation(s.begin(),s.end());
        }
        return s;
        
        // Method 2 --> Recursion 
        
        
    }
};