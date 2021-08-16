// Question Link --> https://leetcode.com/problems/power-of-three/
// Question Link --> https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        if(n%3==0)
            return isPowerOfThree(n/3);
        if(n==1)
            return true;
        return false;   
    }
};


class Solution {
public:
    bool isPowerOfFour(int n) {
        // // Method 1 --> Recursion
        // if(n<=0)
        //     return false;
        // if(n%4==0)
        //     return isPowerOfFour(n/4);
        // if(n==1)
        //     return true;
        // return false;
        
        // Method 2 --> Bit Manipulation
        long long int num = n;
        if(num==0)
            return false;
        if(num==1)
            return true;
        return ((num&(num-1)) == 0);
    }
};