// Question Link --> https://leetcode.com/problems/number-of-digit-one/


class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        for(long long i=1;i<=n;i*=10){
            long long divider = i*10;
            auto fact = (n % divider - i + 1 > 0LL) ? (n % divider - i + 1) : 0LL;
            ans += (n / divider) * i + (fact > i ? i : fact);
        }
        return ans;
    }
};