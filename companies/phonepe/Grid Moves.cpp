// on leetcode and coding mohan as Check if Point Is Reachable

class Solution {
    bool checkPowerOfTwo(int n){
        return (n & (n-1))==0;
    }
public:
    bool isReachable(int x, int y) {
        return checkPowerOfTwo(__gcd(x,y));
    }
};

// Alt:

